/* halton.inc version 1.0.1
 * Persistence of Vision Ray Tracer include file
 *
 * Creates Halton sequences.  For more information, see:
 *   https://en.wikipedia.org/wiki/Halton_sequence
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
#ifndef (Halton_Inc_Temp) #declare Halton_Inc_Temp = version;
#version max (3.5, min (3.8, version));
#ifdef (View_POV_Include_Stack)
  #debug "#include \"halton.inc\" //version 1.0.1\n"
#end

/* Returns a number from a Halton sequence.
 * Arguments:
 *   Base  - the base integer of the sequence: one of the co-prime numbers.
 *   Index - the index into the sequence.  The index is one-based; that is, the
 *           first number in the sequence has Index = 1.
 */
#macro Halton (Base, Index)
  Halton__Check ("Base", Base, 2)
  Halton__Check ("Index", Index, 1)
  #local Halton_i = Index;
  #local Halton_f = 1;
  #local Halton_r = 0;
  #while (Halton_i > 0)
    #local Halton_f = Halton_f / Base;
    #local Halton_r = Halton_r + Halton_f * (mod (Halton_i, Base));
    #local Halton_i = floor (Halton_i / Base);
  #end
  Halton_r
#end

#macro Halton__Check (s_Param, Value, Min)
  #if (Value < Min | floor (Value) != Value)
    #error concat
    ( "Halton(): ", s_Param, " must be an integer ", str (Min, 0, 0),
      " or greater, but ", str (Value, 0, -1), " was used."
    )
  #end
#end

#version Halton_Inc_Temp;
#end
