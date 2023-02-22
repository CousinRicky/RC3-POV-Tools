# Miscellaneous POV-Ray Tools

Collection version 1.0

This is a collection of miscellaneous short include files that I have written for the [Persistence of Vision Raytracer (POV-Ray)](https://www.povray.org/). They require a minimum POV-Ray version of 3.5.

---------------------------------------

## File dotgray.inc v1.0

### Macro `DotGray (Color)`

This is a substitute for POV-Ray’s built-in `.gray` operator that is more accurate with `assumed_gamma 1.0` than `.gray` is. Color system BT.709-6/sRGB is assumed.

---------------------------------------

## File dotgrey.inc v1.0

### Macro `DotGrey (Colour)`

This is a substitute for POV-Ray’s built-in `.gray` operator that is more accurate with `assumed_gamma 1.0` than `.gray` is. Color system BT.709-6/sRGB is assumed.

---------------------------------------

## File halton.inc v1.0.1

### Macro `Halton (Base, Index)`

This macro returns a number from a [Halton sequence](https://en.wikipedia.org/wiki/Halton_sequence).

Arguments:

* `Base` - The base integer of the sequence: one of the co-prime numbers.
* `Index` - The index into the sequence. The index is one-based; that is, the first number in the sequence has `Index` = 1.

### File `halton_example.pov`

This scene description file demonstrates how to use macro `Halton()`.

---------------------------------------

## File srgb.inc v2.0

This file contains tools for converting colors in linear space to [sRGB encoding](https://en.wikipedia.org/wiki/SRGB#Transfer_function_%28%22gamma%22%29), including conversions to hexadecimal strings. Conversions from sRGB encoding to linear are not included, but such conversions should not be needed with POV-Ray 3.7 and later.

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

Converts a value 0...1 to a 2-digit hexadecimal string, without encoding as sRGB, and returns the string. If the argument is negative, `"--"` is returned; if the argument is greater than 1.0, `"++"` is returned.

### Macro `sRGB_Hex_Convert_s (Value)`

Converts a value 0...1 in linear space to an sRGB-encoded 2-digit hexadecimal string, and returns the string. If the argument is negative, `"--"` is returned; if the argument is greater than 1.0, `"++"` is returned.

### Macro `sRGB_Hex_Straight_Color_s (Color)` or `sRGB_Hex_Straight_Colour_s (Colour)`

Converts a color to a 6-digit hexadecimal string, without encoding as sRGB, and returns the string. If a channel value is negative, `"--"` is returned for that channel; if a channel value is greater than 1.0, `"++"` is returned for that channel. The filter and transmit channels are ignored. A scalar argument will be promoted to a color.

### Macro `sRGB_Hex_Convert_Color_s (Color)` or `sRGB_Hex_Convert_Colour_s (Colour)`

Converts a color in linear space to an sRGB-encoded 6-digit hexadecimal string, and returns the string. If a channel value is negative, `"--"` is returned for that channel; if a channel value is greater than 1.0, `"++"` is returned for that channel. The filter and transmit channels are ignored. A scalar argument will be promoted to a color.
