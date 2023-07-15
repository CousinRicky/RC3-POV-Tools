/* srgb.inc version 2.0
 * Persistence of Vision Ray Tracer include file
 *
 * Utilities for converting colors in linear space to sRGB encoding, including
 * conversions to hexadecimal strings.
 *
 * Usage notes:
 *  - The macros all return the converted values without altering their
 *    arguments.
 *  - This file was written for scenes with assumed_gamma 1.0. It will be less
 *    useful for other assumed_gamma settings. 
 *
 * Copyright © 2013 - 2023 Richard Callwood III.  Some rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 *        2013-Dec-04  Created.
 * 1.0    2014-Mar-25  Prepared for public release.
 * 1.0.1  2015-Mar-25  Bug fix: a typo in sRGB_Convert_c() is corrected.
 * 2.0    2023-Feb-21  The license is changed.
 *                     Macros with international spellings are added.
 *                     A more conventional POV-Ray capitalization style is used
 *                      for the macro names.
 *                     View_POV_Include_Stack is utilized.
 * 2.1    2023-Jul-15  Hexadecimal values are rounded before range checking.
 */
#ifndef (sRGB_Inc_Temp) #declare sRGB_Inc_Temp = version;
#version max (3.5, min (3.8, version));
#ifdef (View_POV_Include_Stack)
  #debug "#include \"srgb.inc\" //version 2.0\n"
#end

#declare SRGB__HEX_DIGITS = "0123456789ABCDEF"

/*------------------------------------------------------------------------------
 * Encodes a value 0...1 in linear space as sRGB.
 * From IEC 61966-2-1:1999.
 */
#declare sRGB_fn_Convert = function (x)
{ select
  ( 0.0031308 - x,
    1.055 * pow (x, 1/2.4) - 0.055,
    12.92 * x
  )
}

/*------------------------------------------------------------------------------
 * Encodes a 3-D vector in linear space as sRGB.
 */
#macro sRGB_Convert_v (Vector)
  #local srgb_V = <0,0,0> + Vector;
  < sRGB_fn_Convert (srgb_V.red),
    sRGB_fn_Convert (srgb_V.green),
    sRGB_fn_Convert (srgb_V.blue)
  >
#end

/*------------------------------------------------------------------------------
 * Encodes a color in linear space as sRGB.
 */
#macro sRGB_Convert_c (Color)
  #local srgb_C = color Color;
  < sRGB_fn_Convert (srgb_C.red),
    sRGB_fn_Convert (srgb_C.green),
    sRGB_fn_Convert (srgb_C.blue),
    srgb_C.filter,
    srgb_C.transmit
  >
#end

/*------------------------------------------------------------------------------
 * Converts an integer to a hexadecimal string.
 * Arguments:
 *   I     - The number to convert.  If it is not an integer, it will be
 *           rounded.
 *   Field - The minimum length of the converted string.  The result will be
 *           zero-padded if necessary.
 */
#macro sRGB_Hex_Integer_s (I, Field)
  #local srgb_Sgn = select (I, -1, 0, 1);
  #local srgb_I = floor (abs (I) + 0.5);
  #local srgb_S = "";
  #while (srgb_I > 0)
    #local srgb_S =
      concat (substr (SRGB__HEX_DIGITS, mod (srgb_I, 16) + 1, 1), srgb_S)
    #local srgb_I = floor (srgb_I / 16);
  #end
  #while (strlen (srgb_S) < Field)
    #local srgb_S = concat ("0", srgb_S)
  #end
  #if (srgb_Sgn < 0)
    concat ("-", srgb_S)
  #else
    srgb_S
  #end
#end

/*------------------------------------------------------------------------------
 * Converts a value 0...1 to a two-digit hexadecimal string, without encoding
 * as sRGB.
 * If the rounded hex value is negative, "--" is returned.
 * If the rounded hex value is greater than 1.0, "++" is returned.
 */
#macro sRGB_Hex_Linear_s (Value)
  #local srgb_V = floor (Value * 255 + 0.5);
  #if (srgb_V < 0)
    "--"
  #else #if (srgb_V > 255)
    "++"
  #else
    sRGB_Hex_Integer_s (srgb_V, 2)
  #end
  #end
#end

/*------------------------------------------------------------------------------
 * Converts a value 0...1 in linear space to a 2-digit sRGB-encoded hexadecimal
 * string.
 * If the rounded hex value is negative, "--" is returned.
 * If the rounded hex value is greater than 1.0, "++" is returned.
 */
#macro sRGB_Hex_Convert_s (Value)
  sRGB_Hex_Linear_s (sRGB_fn_Convert (Value))
#end

/*------------------------------------------------------------------------------
 * Converts a color to a 6-digit hexadecimal string, without encoding as sRGB.
 * If a rounded hex channel value is negative, "--" is returned for that
 * channel.
 * If a rounded hex channel value is greater than 1.0, "++" is returned for that
 * channel.
 */
#macro sRGB_Hex_Straight_Color_s (Color)
  #local srgb_C = color (Color);
  concat
  ( sRGB_Hex_Linear_s (srgb_C.red),
    sRGB_Hex_Linear_s (srgb_C.green),
    sRGB_Hex_Linear_s (srgb_C.blue)
  )
#end

/*------------------------------------------------------------------------------
 * Converts a color in linear space to a 6-digit sRGB-encoded hexadecimal
 * string.
 * If a rounded hex channel value is negative, "--" is returned for that
 * channel.
 * If a rounded hex channel value is greater than 1.0, "++" is returned for that
 * channel.
 */
#macro sRGB_Hex_Convert_Color_s (Color)
  sRGB_Hex_Straight_Color_s (sRGB_Convert_v (Color))
#end

//=================== INTERNATIONAL SPELLINGS ==================================

#macro sRGB_Hex_Straight_Colour_s (Colour)
  sRGB_Hex_Straight_Color_s (Colour)
#end

#macro sRGB_Hex_Convert_Colour_s (Colour)
  sRGB_Hex_Straight_Color_s (sRGB_Convert_v (Colour))
#end

//================== GRANDFATHERED CAPITALIZATION ==============================

#macro sRGB_Hex_integer_s (I, Field)
  sRGB_Hex_Integer_s (I, Field)
#end

#macro sRGB_Hex_linear_s (Value)
  sRGB_Hex_Linear_s (Value)
#end

#macro sRGB_Hex_convert_s (Value)
  sRGB_Hex_Convert_s (Value)
#end

#macro sRGB_Hex_straight_color_s (Color)
  sRGB_Hex_Straight_Color_s (Color)
#end

#macro sRGB_Hex_convert_color_s (Color)
  sRGB_Hex_Convert_Color_s (Color)
#end

#version sRGB_Inc_Temp;
#end
