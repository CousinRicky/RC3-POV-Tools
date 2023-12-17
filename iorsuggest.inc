/* iorsuggest.inc version 1.0.1
 * Persistence of Vision Raytracer include file
 *
 * A function that suggests an adjustment to a material's index of refraction
 * that yields reasonably accurate dispersion for most materials.
 *
 * Background: IORs are normally given at wavelength D, but POV-Ray's dispersion
 * algorithm assumes that the given IOR is for a wavelength midway between red
 * and violet.  For a discussion, see:
 *  https://news.povray.org/povray.binaries.images/thread/%3C58eee63d%40news.povray.org%3E/
 *
 * Copyright © 2018, 2023 Richard Callwood III.  Some rights reserved.
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
 * 1.0    2018-Dec-18  Created.
 *        2019-Oct-27  Administrative.
 * 1.0.1  2023-Dec-17  Compatibility is extended to POV-Ray 3.5.
 *                     View_POV_Include_Stack is utilized.
 */
#ifndef (IORSuggest_Inc_Temp) #declare IORSuggest_Inc_Temp = version;
#version max (3.5, min (3.8, version));
#ifdef (View_POV_Include_Stack)
  #debug "#include \"iorsuggest.inc\" //version 1.0.1\n"
#end

/* Arguments:
 *   x - The D-line index of refraction
 *   y - The dispersion
 */
#declare IORSuggest_fn = function (x, y) { (y + 2.31) * x / 3.31 }

#version IORSuggest_Inc_Temp;
#end
