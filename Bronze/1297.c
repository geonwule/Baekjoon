#include <stdio.h>

// int main()
// {
//     float D, H, W;
//     scanf("%f %f %f", &D, &H, &W);
//     float sum = H + W;
//     float r_h = (D * D) / sum * H;
//     float r_w = (D * D) / sum * W;
//     float a = 10, b = 3;
//     printf("%d %f", (int)r_h, r_w);
// }

float ret_h_out(float r_h)
{
    float ret_h = 1;
    while (1)
    {
        if (ret_h * ret_h == r_h)
            break;
        if (ret_h * ret_h > r_h)
        {
            ret_h -= 1;
            break;
        }
        ret_h += 1;
    }
    return (ret_h);
}

float ret_w_out(float r_w)
{
    float ret_w = 2;

    while (1)
    {
        if (ret_w * ret_w == r_w)
            break;
        if (ret_w * ret_w > r_w)
        {
            ret_w -= 1;
            break;
        }
        ret_w += 1;
    }
    return (ret_w);
}

int main()
{
    float D, H, W;
    scanf("%f %f %f", &D, &H, &W);
    float sum = H + W;
    float r_h = (D * D) / sum * H;
    float r_w = (D * D) / sum * W;
    float ret_h = ret_h_out(r_h);
    float ret_w = ret_w_out(r_w);
    printf("%d %d", (int)ret_h, (int)ret_w);
}