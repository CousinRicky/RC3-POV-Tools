# Miscellaneous POV-Ray Tools

Collection version 2.0, 2023 December 17

This is a collection of miscellaneous short include files that I have written for the [Persistence of Vision Raytracer (POV-Ray)](https://www.povray.org/). They require a minimum POV-Ray version of 3.5.

----------------------------------------

## Files dotgray.inc and dotgrey.inc, v1.0.1

### Macro `DotGray (Color)`

### Macro `DotGrey (Colour)`

These are substitutes for POV-Ray’s built-in `.gray` operator that are more accurate with `assumed_gamma 1.0` than `.gray` is. Color system BT.709-6/sRGB is assumed.

**Important:** This module is designed for use with `assumed_gamma 1.0` only! If your color is sRGB-encoded (which most are), then it must be decoded using one of the srgb keywords before being passed to `DotGray()` or `DotGrey()`. For example:

    DotGray (srgb <MyRed, MyGreen, MyBlue> / 255)
    DotGray (srgbft MysRGBEncodedColor)

Alternatively, if you know that your color is encoded with a particular gamma, or if you are using a version of POV-Ray prior to 3.7, you can use the power function. For example:

    #include "math.inc"
    DotGray (VPow (<MyRed, MyGreen, MyBlue> / 255, 2.2))
    DotGray (VPow (MyAdobeEncodedColor, 2.2))

If your color specification is already linear, there is no need to decode it.

Please see the thread “[strange problem with srgb color in light_source](https://news.povray.org/povray.general/thread/%3Cweb.60649d9bb9b7dccdd98418916e066e29%40news.povray.org%3E/)” for a discussion of gamma decoding in POV-Ray.

----------------------------------------

## File halton.inc v1.0.1

### Macro `Halton (Base, Index)`

This macro returns a number from a [Halton sequence](https://en.wikipedia.org/wiki/Halton_sequence).

Arguments:

* `Base` - The base integer of the sequence: one of the co-prime numbers.
* `Index` - The index into the sequence. The index is one-based; that is, the first number in the sequence has `Index` = 1.

### File `halton_example.pov`

This scene description file demonstrates how to use macro `Halton()`.

----------------------------------------

## File iorsuggest.inc v1.0.1

POV-Ray’s dispersion algorithm assumes that the given IOR is for a wavelength midway between red and violet. However, IORs are normally given at wavelength D, which is closer to the red end of the visible spectrum. See [SpectralRender/ior.inc dispersion mismatches](https://news.povray.org/povray.binaries.images/thread/%3C58eee63d%40news.povray.org%3E/) for a discussion. This file provides a function that *suggests* an adjustment to a material’s index of refraction that yields reasonably accurate dispersion for most materials.

### function `IORSuggest_fn (x, y)`

Arguments:

* `x` - The D-line index of refraction
* `y` - The dispersion

For POV-Ray 3.7 and later, argument values can be obtained from `ior.inc`. For older versions, `consts.inc` provides a more limited selection of values. Note that the values for diamond in `consts.inc` are inaccurate.

Be aware that POV-Ray 3.5 and 3.6 use an inferior dispersion algorithm, and 3.5 has a serious bug when used with Fresnel reflection and `conserve_energy`.

----------------------------------------

## File srgb.inc v3.0

This file contains tools for converting colors between linear space and [sRGB encoding](https://en.wikipedia.org/wiki/SRGB#Transfer_function_%28%22gamma%22%29), including conversions to hexadecimal strings.

Usage notes:

* The macros all return the converted values without altering their arguments.
* This module was written for scenes with `assumed_gamma 1.0`. It will be less useful for other `assumed_gamma` settings.

### Function `sRGB_fn_Convert (x)`

Encodes a scalar value 0...1 in linear space as sRGB, and returns the encoded value.

### Macro `sRGB_Convert_v (Vector)`

Encodes a 3-D vector in linear space as sRGB, and returns the encoded vector. A scalar argument will be promoted to a vector.

### Macro `sRGB_Convert_c (Color)`

Encodes a color in linear space as sRGB, and returns the encoded color. The filter and transmit channels are returned unaltered. A scalar or vector argument will be promoted to a color.

### Macro `sRGB_Hex_Integer_s (I, Field)`

Converts an integer to a hexadecimal string, and returns the string.

Arguments:

* `I` - The number to convert. If it is not an integer, it will be rounded.
* `Field` - The minimum length of the converted string. The result will be zero-padded if necessary.

### Macro `sRGB_Hex_Linear_s (Value)`

Converts a value 0...1 to a 2-digit hexadecimal string, without encoding as sRGB, and returns the string. If the rounded hexadecimal value is negative, `"--"` is returned; if the rounded hexadecimal value is greater than 1.0, `"++"` is returned.

### Macro `sRGB_Hex_Convert_s (Value)`

Converts a value 0...1 in linear space to an sRGB-encoded 2-digit hexadecimal string, and returns the string. If the rounded hexadecimal value is negative, `"--"` is returned; if the rounded hexadecimal value is greater than 1.0, `"++"` is returned.

### Macro `sRGB_Hex_Straight_Color_s (Color)` or `sRGB_Hex_Straight_Colour_s (Colour)`

Converts a color to a 6-digit hexadecimal string, without encoding as sRGB, and returns the string. If a rounded hexadecimal channel value is negative, `"--"` is returned for that channel; if a rounded hexadecimal channel value is greater than 1.0, `"++"` is returned for that channel. The filter and transmit channels are ignored. A scalar argument will be promoted to a color.

### Macro `sRGB_Hex_Convert_Color_s (Color)` or `sRGB_Hex_Convert_Colour_s (Colour)`

Converts a color in linear space to an sRGB-encoded 6-digit hexadecimal string, and returns the string. If a rounded hexadecimal channel value is negative, `"--"` is returned for that channel; if a rounded hexadecimal channel value is greater than 1.0, `"++"` is returned for that channel. The filter and transmit channels are ignored. A scalar argument will be promoted to a color.

---

The remaining tools are included for the sake of older POV-Ray versions that do not have the `srgb` series of keywords.

### Function `sRGB_fn_Decode (x)`

Decodes an sRGB-encoded scalar value 0...1 to linear space, and returns the decoded value. If the argument is a byte value, then divide it by 255 before passing it to this function.

### Macro `sRGB_Decode_v (Vector)`

Decodes an sRGB-encoded 3-D vector to linear space, and returns the decoded vector. A scalar argument will be promoted to a vector. If the argument is a byte triplet, then divide it by 255 before passing it to this macro.

### Macro `sRGB_Decode_c (Color)`

Decodes an sRGB-encoded color to linear space, and returns the decoded color. The filter and transmit channels are returned unaltered. A scalar or vector argument will be promoted to a color.
