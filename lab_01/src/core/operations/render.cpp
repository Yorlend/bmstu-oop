
#include "render.hpp"
#include "core/utils/error_codes.hpp"
#include "core/utils/projection/projection.hpp"

bool is_valid(IN const render_params& params)
{
    return params.painter != nullptr && params.width > 0 && params.height > 0;
}

static void draw_line(IN QPainter& painter, IN const line& line)
{
    point p1 = line.start;
    point p2 = line.end;

    painter.drawLine(p1.x, p1.y, p2.x, p2.y);
}

static void translate(QPainter& painter, int dx, int dy)
{
    painter.translate(dx, dy);
}

static int get_width(IN const render_params& params)
{
    return params.width;
}

static int get_height(IN const render_params& params)
{
    return params.height;
}

static int paint_projection(IN const render_params& params, IN const projection& proj)
{
    if (!is_valid(params) || !is_valid(proj))
        return ARGS_ERROR;

    int width = get_height(params);
    int height = get_width(params);

    translate(*params.painter, width / 2, height / 2);

    for (size_t i = 0; i < proj.size; i++)
        draw_line(*params.painter, proj.data[i]);

    return NO_ERRORS;
}

int render(const model &model, const render_params &params)
{
    if (!is_valid(params) || !is_valid(model))
        return ARGS_ERROR;

    projection proj{};
    int status = project(proj, model);

    if (status == NO_ERRORS)
    {
        status = paint_projection(params, proj);
        free_projection(proj);
    }

    return status;
}
