#include <iostream>
#include <vector>

// Forward declerations
struct colour;
void flood_fill();
typedef std::vector<std::vector<colour>> array_2d;

struct colour
{
    float r, g, b, a;
    bool operator==(const colour& other) const
    {
        return (r == other.r && g == other.g && b == other.b && a == other.a);    
    }
};

void flood_fill(colour& replacement, colour& target, array_2d& arr, size_t r, size_t c)
{
    if (target == replacement)
    {
        return;
    }
    if (!(arr[r][c] == target))
    {
        return;
    }

    arr[r][c] == replacement;

    if(r + 1 < arr.size())
    {
        flood_fill(replacement, target, arr, r + 1, c);
    }

    if(r - 1 > 0)
    {
        flood_fill(replacement, target, arr, r - 1, c);
    }

    if(c + 1 < arr[r].size())
    {
        flood_fill(replacement, target, arr, r, c + 1);
    }

    if(c - 1 > 0)
    {
        flood_fill(replacement, target, arr, r, c - 1);
    }
}
