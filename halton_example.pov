/* halton_example.pov version 1.0.1
 * Persistence of Vision Ray Tracer scene description file
 *
 * An example scene that uses halton.inc to generate Halton sequences.
 *
 * Copyright © 2020, 2023 Richard Callwood III.  Some rights reserved.
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
 * 1.0    2020-Mar-26  Created.
 * 1.0.1  2023-Feb-20  The POV-Ray version is auto-detected within a range.
 *                     The license is changed.
 */
#version max (3.5, min (3.8, version));

#include "halton.inc"

global_settings { assumed_gamma 1 }

camera
{ orthographic
  location <2/3, 0.5, -1>
  right 1.4 * x
  up 1.05 * y
}

background { rgb 1 }

light_source { <-1, 1, -2> * 1000, rgb 1 parallel point_at 0 }

union
{ #declare I = 1;
  #while (I <= 100)
    sphere { <Halton (2, I) * 4/3, Halton (3, I), 0>, 0.025 }
    #declare I = I + 1;
  #end
  pigment { red 1 }
}
