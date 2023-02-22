/* dotgrey.inc version 1.0-international
 * Persistence of Vision Raytracer include file
 *
 * Implement the ITU-R BT.709-6 luminance function.
 * http://www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.709-6-201506-I!!PDF-E.pdf
 * page 6, item 3.2
 *
 * Copyright © 2023 Richard Callwood III.  Some rights reserved.
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
 * Vers.  Date         Notes
 * -----  ----         -----
 * 1.0    2023-Feb-20  Created.
 */
#ifndef (DotGrey_Inc_Temp) #declare DotGrey_Inc_Temp = version;
#version 3.5;
#ifdef (View_POV_Include_Stack)
  #debug "#include \"dotgrey.inc\" //version 1.0\n"
#end

#macro DotGrey (Colour)
  #local dotgrey_C = colour Colour;
  (0.2126 * dotgrey_C.red + 0.7152 * dotgrey_C.green + 0.0722 * dotgrey_C.blue)
#end

#version DotGrey_Inc_Temp;
#end
