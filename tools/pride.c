#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rgb_to_xterm256.h"

uint32_t xterm256_colors[] = {
    0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080,
    0xc0c0c0, 0x808080, 0xff0000, 0x00ff00, 0xffff00, 0x0000ff, 0xff00ff,
    0x00ffff, 0xffffff, 0x000000, 0x00005f, 0x000087, 0x0000af, 0x0000d7,
    0x0000ff, 0x005f00, 0x005f5f, 0x005f87, 0x005faf, 0x005fd7, 0x005fff,
    0x008700, 0x00875f, 0x008787, 0x0087af, 0x0087d7, 0x0087ff, 0x00af00,
    0x00af5f, 0x00af87, 0x00afaf, 0x00afd7, 0x00afff, 0x00d700, 0x00d75f,
    0x00d787, 0x00d7af, 0x00d7d7, 0x00d7ff, 0x00ff00, 0x00ff5f, 0x00ff87,
    0x00ffaf, 0x00ffd7, 0x00ffff, 0x5f0000, 0x5f005f, 0x5f0087, 0x5f00af,
    0x5f00d7, 0x5f00ff, 0x5f5f00, 0x5f5f5f, 0x5f5f87, 0x5f5faf, 0x5f5fd7,
    0x5f5fff, 0x5f8700, 0x5f875f, 0x5f8787, 0x5f87af, 0x5f87d7, 0x5f87ff,
    0x5faf00, 0x5faf5f, 0x5faf87, 0x5fafaf, 0x5fafd7, 0x5fafff, 0x5fd700,
    0x5fd75f, 0x5fd787, 0x5fd7af, 0x5fd7d7, 0x5fd7ff, 0x5fff00, 0x5fff5f,
    0x5fff87, 0x5fffaf, 0x5fffd7, 0x5fffff, 0x870000, 0x87005f, 0x870087,
    0x8700af, 0x8700d7, 0x8700ff, 0x875f00, 0x875f5f, 0x875f87, 0x875faf,
    0x875fd7, 0x875fff, 0x878700, 0x87875f, 0x878787, 0x8787af, 0x8787d7,
    0x8787ff, 0x87af00, 0x87af5f, 0x87af87, 0x87afaf, 0x87afd7, 0x87afff,
    0x87d700, 0x87d75f, 0x87d787, 0x87d7af, 0x87d7d7, 0x87d7ff, 0x87ff00,
    0x87ff5f, 0x87ff87, 0x87ffaf, 0x87ffd7, 0x87ffff, 0xaf0000, 0xaf005f,
    0xaf0087, 0xaf00af, 0xaf00d7, 0xaf00ff, 0xaf5f00, 0xaf5f5f, 0xaf5f87,
    0xaf5faf, 0xaf5fd7, 0xaf5fff, 0xaf8700, 0xaf875f, 0xaf8787, 0xaf87af,
    0xaf87d7, 0xaf87ff, 0xafaf00, 0xafaf5f, 0xafaf87, 0xafafaf, 0xafafd7,
    0xafafff, 0xafd700, 0xafd75f, 0xafd787, 0xafd7af, 0xafd7d7, 0xafd7ff,
    0xafff00, 0xafff5f, 0xafff87, 0xafffaf, 0xafffd7, 0xafffff, 0xd70000,
    0xd7005f, 0xd70087, 0xd700af, 0xd700d7, 0xd700ff, 0xd75f00, 0xd75f5f,
    0xd75f87, 0xd75faf, 0xd75fd7, 0xd75fff, 0xd78700, 0xd7875f, 0xd78787,
    0xd787af, 0xd787d7, 0xd787ff, 0xd7af00, 0xd7af5f, 0xd7af87, 0xd7afaf,
    0xd7afd7, 0xd7afff, 0xd7d700, 0xd7d75f, 0xd7d787, 0xd7d7af, 0xd7d7d7,
    0xd7d7ff, 0xd7ff00, 0xd7ff5f, 0xd7ff87, 0xd7ffaf, 0xd7ffd7, 0xd7ffff,
    0xff0000, 0xff005f, 0xff0087, 0xff00af, 0xff00d7, 0xff00ff, 0xff5f00,
    0xff5f5f, 0xff5f87, 0xff5faf, 0xff5fd7, 0xff5fff, 0xff8700, 0xff875f,
    0xff8787, 0xff87af, 0xff87d7, 0xff87ff, 0xffaf00, 0xffaf5f, 0xffaf87,
    0xffafaf, 0xffafd7, 0xffafff, 0xffd700, 0xffd75f, 0xffd787, 0xffd7af,
    0xffd7d7, 0xffd7ff, 0xffff00, 0xffff5f, 0xffff87, 0xffffaf, 0xffffd7,
    0xffffff, 0x080808, 0x121212, 0x1c1c1c, 0x262626, 0x303030, 0x3a3a3a,
    0x444444, 0x4e4e4e, 0x585858, 0x626262, 0x6c6c6c, 0x767676, 0x808080,
    0x8a8a8a, 0x949494, 0x9e9e9e, 0xa8a8a8, 0xb2b2b2, 0xbcbcbc, 0xc6c6c6,
    0xd0d0d0, 0xdadada, 0xe4e4e4, 0xeeeeee
};

static const unsigned char legacy_xterm256_colors_3bits[] = {
    0x00, 0x11, 0x12, 0x13, 0x14, 0x0c, 0x00, 0x00, 0x16, 0x17, 0x18, 0x19,
    0x1a, 0x1b, 0x16, 0x16, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x1c, 0x1c,
    0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x22, 0x22, 0x28, 0x29, 0x2a, 0x2b,
    0x2c, 0x2d, 0x28, 0x28, 0x0a, 0x2f, 0x30, 0x31, 0x32, 0x0e, 0x0a, 0x0a,
    0x00, 0x11, 0x12, 0x13, 0x14, 0x0c, 0x00, 0x00, 0x00, 0x11, 0x12, 0x13,
    0x14, 0x0c, 0x00, 0x00, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x34, 0x34,
    0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x3a, 0x3a, 0x40, 0x41, 0x42, 0x43,
    0x44, 0x45, 0x40, 0x40, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x46, 0x46,
    0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x4c, 0x4c, 0x52, 0x53, 0x54, 0x55,
    0x56, 0x57, 0x52, 0x52, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x34, 0x34,
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x34, 0x34, 0x58, 0x59, 0x5a, 0x5b,
    0x5c, 0x5d, 0x58, 0x58, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x5e, 0x5e,
    0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x64, 0x64, 0x6a, 0x6b, 0x6c, 0x6d,
    0x6e, 0x6f, 0x6a, 0x6a, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x70, 0x70,
    0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x76, 0x76, 0x58, 0x59, 0x5a, 0x5b,
    0x5c, 0x5d, 0x58, 0x58, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x58, 0x58,
    0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x7c, 0x7c, 0x82, 0x83, 0x84, 0x85,
    0x86, 0x87, 0x82, 0x82, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x88, 0x88,
    0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x8e, 0x8e, 0x94, 0x95, 0x96, 0x97,
    0x98, 0x99, 0x94, 0x94, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0x9a, 0x9a,
    0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x7c, 0x7c, 0x7c, 0x7d, 0x7e, 0x7f,
    0x80, 0x81, 0x7c, 0x7c, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa0, 0xa0,
    0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xa6, 0xa6, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xac, 0xac, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb2, 0xb2,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xb8, 0xb8, 0xbe, 0xbf, 0xc0, 0xc1,
    0xc2, 0xc3, 0xbe, 0xbe, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa0, 0xa0,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa0, 0xa0, 0x09, 0xc5, 0xc6, 0xc7,
    0xc8, 0x0d, 0x09, 0x09, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xca, 0xca,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd0, 0xd0, 0xd6, 0xd7, 0xd8, 0xd9,
    0xda, 0xdb, 0xd6, 0xd6, 0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xdc, 0xdc,
    0x0b, 0xe3, 0xe4, 0xe5, 0xe6, 0x0f, 0x0b, 0x0b, 0x09, 0xc5, 0xc6, 0xc7,
    0xc8, 0x0d, 0x09, 0x09, 0x09, 0xc5, 0xc6, 0xc7, 0xc8, 0x0d, 0x09, 0x09,
    0x00, 0x11, 0x12, 0x13, 0x14, 0x0c, 0x00, 0x00, 0x16, 0x17, 0x18, 0x19,
    0x1a, 0x1b, 0x16, 0x16, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x1c, 0x1c,
    0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x22, 0x22, 0x28, 0x29, 0x2a, 0x2b,
    0x2c, 0x2d, 0x28, 0x28, 0x0a, 0x2f, 0x30, 0x31, 0x32, 0x0e, 0x0a, 0x0a,
    0x00, 0x11, 0x12, 0x13, 0x14, 0x0c, 0x00
};

static const unsigned char gray_colors[] = {
    0x00, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xf0, 0x3b,
    0xf1, 0xf2, 0xf3, 0x08, 0x66, 0xf5, 0xf6, 0xf7, 0xf8, 0x91, 0xf9,
    0xfa, 0x07, 0xfb, 0xfc, 0xbc, 0xfd, 0xfe, 0xff, 0x0f
};

unsigned char
new_rgb_to_xterm256(unsigned char color_r,
                    unsigned char color_g,
                    unsigned char color_b) {

    if (color_r == color_g && color_g == color_b) {
        return 232 + (color_r * 23) / 255;
    }

    unsigned char r_index = (color_r * 5) / 255;
    unsigned char g_index = (color_g * 5) / 255;
    unsigned char b_index = (color_b * 5) / 255;

    unsigned char result = 16 + 36 * r_index + 6 * g_index + b_index;

    return result;
}

unsigned char
old_rgb_to_xterm256(unsigned char r, unsigned char g, unsigned char b) {

    unsigned char c3r = 0;
    unsigned char c3g = 0;
    unsigned char c3b = 0;

    if (r > 0) {
        c3r = 1;
        while (r > 0x5f) {
            r -= 0x28;
            c3r += 1;
        }
    }

    if (g > 0) {
        c3g = 1;
        while (g > 0x5f) {
            g -= 0x28;
            c3g += 1;
        }
    }

    if (b > 0) {
        c3b = 1;
        while (b > 0x5f) {
            b -= 0x28;
            c3b += 1;
        }
    }

    return legacy_xterm256_colors_3bits[(c3r << 6) | (c3g << 3) | c3b];
}

uint8_t
bit_8to3(uint8_t input) {
    uint8_t output = 0;
    if (input > 0) {
        output = 1;
        while (input > 0x5f) {
            input -= 0x28;
            output += 1;
        }
    }
    return output;
}

uint8_t
bit_3to8(uint8_t input) {
    static uint8_t incs[] = { 0x00, 0x5f, 0x87, 0xaf, 0xd7, 0xff };

    if (input >= sizeof(incs)) {
        return 0;
    }

    return incs[input];
}

void
split_rgb(uint32_t input,
          uint8_t *output_r,
          uint8_t *output_g,
          uint8_t *output_b) {
    *output_r = (input >> 16) & 0xFF;
    *output_g = (input >> 8) & 0xFF;
    *output_b = input & 0xFF;
}

uint32_t
join_rgb(uint8_t input_r, uint8_t input_g, uint8_t input_b) {
    return ((uint32_t)input_r << 16) | ((uint32_t)input_g << 8) |
           (uint32_t)input_b;
}

int
command_rgb2xterm() {
    int len = 0;
    uint32_t color = 0;
    uint8_t r, g, b;
    while (scanf("%x%n\n", &color, &len) == 1) {
        if (len != 6) {
            break;
        }
        split_rgb(color, &r, &g, &b);
        printf("%d\n", rgb_to_xterm256(r, g, b));
    }
    return 0;
}

int
command_original() {
    int len = 0;
    uint32_t color = 0;
    while (scanf("%x%n\n", &color, &len) == 1) {
        if (len != 6) {
            break;
        }
        uint16_t i = 0;
        uint8_t id = 0;
        while (i < sizeof(xterm256_colors) / sizeof(*xterm256_colors)) {
            if (xterm256_colors[i] == color) {
                id = i;
                break;
            }
            i++;
        }
        printf("%d\n", id);
    }
    return 0;
}

int
command_xterm2rgb() {
    int i = 0;
    while (scanf("%d\n", &i) == 1) {
        if (i < 0 || i > (sizeof(xterm256_colors) / sizeof(*xterm256_colors))) {
            break;
        }
        printf("%06x\n", xterm256_colors[i]);
    }
    return 0;
}

int
command_10to16() {
    int i = 0;
    while (scanf("%d\n", &i) == 1) {
        printf("%02x\n", i);
    }
    return 0;
}

int
command_dornelles() {
    int len = 0;
    uint32_t color = 0;
    uint8_t r, g, b;
    while (scanf("%x%n\n", &color, &len) == 1) {
        if (len != 6) {
            break;
        }
        split_rgb(color, &r, &g, &b);
        printf("%d\n", old_rgb_to_xterm256(r, g, b));
    }
    return 0;
}

int
command_mateus() {
    int len = 0;
    uint32_t color = 0;
    uint8_t r, g, b;
    while (scanf("%x%n\n", &color, &len) == 1) {
        if (len != 6) {
            break;
        }
        split_rgb(color, &r, &g, &b);
        printf("%d\n", new_rgb_to_xterm256(r, g, b));
    }
    return 0;
}

int
command_ladygaga() {
    uint32_t i = 0;
    uint8_t r, g, b;

    while (i < 0x1b7) {
        b = i & 0x7;
        g = (i >> 3) & 0x7;
        r = (i >> 6) & 0x7;
        r = r ^ 7 ? r : 0;
        g = g ^ 7 ? g : 0;
        b = b ^ 7 ? b : 0;
        printf("%06x\n", join_rgb(r, g, b));
        i++;
    }

    return 0;
}

int
command_beyonce() {
    int i = 0;
    while (scanf("%d\n", &i) == 1) {
        printf("\033[48;5;%dm  ", i);
    }
    printf("\n\033[0m");
    return 0;
}

int
command_range_rgb() {
    uint16_t i = 0;
    while (i < sizeof(xterm256_colors) / sizeof(*xterm256_colors)) {
        printf("%06x\n", xterm256_colors[i++]);
    }
    return 0;
}

int
command_range_all() {
    uint16_t i = 0;
    while (i < sizeof(xterm256_colors) / sizeof(*xterm256_colors)) {
        printf("%d\n", i++);
    }
    return 0;
}

int
command_range_term() {
    uint16_t i = 0;
    while (i < 16) {
        printf("%d\n", i++);
    }
    return 0;
}

int
command_range_xterm() {
    uint16_t i = 17;
    while (i < 231) {
        printf("%d\n", i++);
    }
    return 0;
}

int
command_range_gray() {
    uint16_t i = 0;
    while (i < sizeof(gray_colors) / sizeof(*gray_colors)) {
        printf("%d\n", gray_colors[i++]);
    }
    return 0;
}

int
command_b8to3() {
    int len = 0;
    uint32_t color = 0;
    uint8_t r, g, b;
    while (scanf("%x%n\n", &color, &len) == 1) {
        if (len != 6) {
            break;
        }
        split_rgb(color, &r, &g, &b);
        printf("%06x\n", join_rgb(bit_8to3(r), bit_8to3(g), bit_8to3(b)));
    }
    return 0;
}

int
command_b3to8() {
    int len = 0;
    uint32_t color = 0;
    uint8_t r, g, b;
    while (scanf("%x%n\n", &color, &len) == 1) {
        if (len != 6) {
            break;
        }
        split_rgb(color, &r, &g, &b);
        printf("%06x\n", join_rgb(bit_3to8(r), bit_3to8(g), bit_3to8(b)));
    }
    return 0;
}

const struct {
    const char *str;
    int (*func)(void);
} command_list[] = {
    { "rgb", command_range_rgb }, // clang-format off
    { "823", command_b8to3 },
    { "328", command_b3to8 },
    { "10216", command_10to16 },
    { "all", command_range_all},
    { "gray", command_range_gray },
    { "term", command_range_term},
    { "xterm", command_range_xterm },
    { "xterm2rgb", command_xterm2rgb },
    { "rgb2xterm", command_rgb2xterm },
    { "original", command_original },
    { "dornelles", command_dornelles},
    { "mateusgpt", command_mateus},
    { "ladygaga", command_ladygaga },
    { "beyonce", command_beyonce } // clang-format on
};

int
main(int argc, char *argv[]) {
    uint8_t i = 0;
    if (argc < 2) {
        fprintf(stderr, "command list:");
        while (i < sizeof(command_list) / sizeof(*command_list)) {
            fprintf(stderr, " %s", command_list[i++].str);
        }
        fprintf(stderr, "\n");
        return 1;
    }

    while (i < sizeof(command_list) / sizeof(*command_list)) {
        if (strcmp(argv[1], command_list[i].str) == 0) {
            return command_list[i].func();
        }
        i++;
    }

    fprintf(stderr, "command not found: %s\n", argv[1]);
    return 1;
}
