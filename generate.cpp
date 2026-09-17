#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

#define MAX_POSITIVE 30
#define MAX_NEGATIVE -30

#define BAR_SYMBOL 'H'
#define BAR_SYMBOL_WIDTH 1
#define BAR_SYMBOL_HEIGHT 1

#define AXIS_SYMBOL '-'
#define AXIS_SYMBOL_WIDTH 1
#define AXIS_SYMBOL_HEIGHT 1

#define EMPTY_SYMBOL ' '

#define BAR_PADDING 2
#define TOP_PADDING 4
#define BOTTOM_PADDING 4

int max_val(const std::vector<int> &all_values)
{
    int max_value = MAX_NEGATIVE;

    for (const int a : all_values)
    {
        if (a > max_value)
        {
            max_value = a;
        }
    }

    return max_value;
}

int height_of_graph(const std::vector<int> &all_values)
{
    int padding_spaces = TOP_PADDING + BOTTOM_PADDING;
    int max_height = max_val(all_values) * BAR_SYMBOL_HEIGHT;

    return padding_spaces + max_height + AXIS_SYMBOL_HEIGHT;
}

int width_of_graph(const std::vector<int> &all_values)
{
    int padding_spaces = BAR_PADDING * all_values.size();
    int bar_positions = all_values.size() * BAR_SYMBOL_WIDTH;

    return padding_spaces + bar_positions;
}

std::pair<int, int> generate_dimensions(
    const std::vector<int> &all_values)
{
    int height = height_of_graph(all_values);
    int width = width_of_graph(all_values);

    return {height, width};
}

void generate_graph(
    const std::vector<int> &all_values,
    std::fstream &output_file)
{
    if (all_values.empty())
    {
        return;
    }

    int max_height = max_val(all_values);

    for (int i = 0; i < TOP_PADDING; ++i)
    {
        output_file << '\n';
    }

    for (int row = max_height; row >= 1; --row)
    {
        for (const int value : all_values)
        {
            // Space before each bar
            for (int i = 0; i < BAR_PADDING; ++i)
            {
                output_file << EMPTY_SYMBOL;
            }

            if (value >= row)
            {
                output_file << BAR_SYMBOL;
            }
            else
            {
                output_file << EMPTY_SYMBOL;
            }
        }

        output_file << '\n';
    }

    for (std::size_t i = 0; i < all_values.size(); ++i)
    {
        for (int j = 0; j < BAR_PADDING; ++j)
        {
            output_file << AXIS_SYMBOL;
        }

        output_file << AXIS_SYMBOL;
    }

    output_file << '\n';

    for (int i = 0; i < BOTTOM_PADDING; ++i)
    {
        output_file << '\n';
    }
}
