// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Resources definitions.
//
// Automatically generated with:
// make resources


#ifndef MIDIPAL_RESOURCES_H_
#define MIDIPAL_RESOURCES_H_


#include "avrlib/base.h"

#include <avr/pgmspace.h>


#include "avrlib/resources_manager.h"

namespace midipal {

typedef uint16_t ResourceId;

extern const prog_char* string_table[];

extern const prog_uint16_t* lookup_table_table[];

extern const prog_uint8_t* character_table[];

extern const prog_uint8_t* waveform_table[];

extern const prog_uint16_t lut_res_arpeggiator_patterns[] PROGMEM;
extern const prog_uint16_t lut_res_drum_patterns[] PROGMEM;
extern const prog_uint16_t lut_res_groove_swing[] PROGMEM;
extern const prog_uint16_t lut_res_groove_shuffle[] PROGMEM;
extern const prog_uint16_t lut_res_groove_push[] PROGMEM;
extern const prog_uint16_t lut_res_groove_lag[] PROGMEM;
extern const prog_uint16_t lut_res_groove_human[] PROGMEM;
extern const prog_uint16_t lut_res_groove_monkey[] PROGMEM;
extern const prog_uint16_t lut_res_euclidian_patterns[] PROGMEM;
extern const prog_uint16_t lut_res_scale_0[] PROGMEM;
extern const prog_uint16_t lut_res_scale_1[] PROGMEM;
extern const prog_uint16_t lut_res_scale_2[] PROGMEM;
extern const prog_uint16_t lut_res_scale_3[] PROGMEM;
extern const prog_uint16_t lut_res_scale_4[] PROGMEM;
extern const prog_uint16_t lut_res_scale_5[] PROGMEM;
extern const prog_uint16_t lut_res_scale_6[] PROGMEM;
extern const prog_uint16_t lut_res_scale_7[] PROGMEM;
extern const prog_uint16_t lut_res_scale_8[] PROGMEM;
extern const prog_uint16_t lut_res_scale_9[] PROGMEM;
extern const prog_uint16_t lut_res_scale_10[] PROGMEM;
extern const prog_uint16_t lut_res_scale_11[] PROGMEM;
extern const prog_uint16_t lut_res_scale_12[] PROGMEM;
extern const prog_uint16_t lut_res_scale_13[] PROGMEM;
extern const prog_uint16_t lut_res_scale_14[] PROGMEM;
extern const prog_uint16_t lut_res_scale_15[] PROGMEM;
extern const prog_uint16_t lut_res_scale_16[] PROGMEM;
extern const prog_uint16_t lut_res_scale_18[] PROGMEM;
extern const prog_uint16_t lut_res_scale_19[] PROGMEM;
extern const prog_uint16_t lut_res_scale_20[] PROGMEM;
extern const prog_uint16_t lut_res_scale_21[] PROGMEM;
extern const prog_uint16_t lut_res_scale_22[] PROGMEM;
extern const prog_uint16_t lut_res_scale_23[] PROGMEM;
extern const prog_uint16_t lut_res_scale_24[] PROGMEM;
extern const prog_uint16_t lut_res_increments[] PROGMEM;
extern const prog_uint8_t chr_res_digits_10[] PROGMEM;
extern const prog_uint8_t chr_res_sequencer_icons[] PROGMEM;
extern const prog_uint8_t wav_res_lfo_waveforms[] PROGMEM;
#define STR_RES_CC_KNOB 0  // cc knob
#define STR_RES_CHORDMEM 1  // chordmem
#define STR_RES_CLOCK 2  // clock
#define STR_RES_DIVIDER 3  // divider
#define STR_RES_CHNFILTR 4  // chnfiltr
#define STR_RES_CHNMERGR 5  // chnmergr
#define STR_RES_USER_PRG 6  // user prg
#define STR_RES_DISPATCH 7  // dispatch
#define STR_RES_DRUMS 8  // drums
#define STR_RES_EAR_GAME 9  // ear game
#define STR_RES_MONITOR 10  // monitor
#define STR_RES_CC_LFO_1 11  // cc lfo 1
#define STR_RES_CC_LFO_2 12  // cc lfo 2
#define STR_RES_CC_LFO_3 13  // cc lfo 3
#define STR_RES_CC_LFO_4 14  // cc lfo 4
#define STR_RES_CC_LFO_5 15  // cc lfo 5
#define STR_RES_CC_LFO_6 16  // cc lfo 6
#define STR_RES_CC_LFO_7 17  // cc lfo 7
#define STR_RES_CC_LFO_8 18  // cc lfo 8
#define STR_RES_SETTINGS 19  // settings
#define STR_RES_NOTENUKE 20  // notenuke
#define STR_RES_SYSXDUMP 21  // sysxdump
#define STR_RES___RESET 22  // ??reset
#define STR_RES___V1_3__ 23  // ¥ v1.3 ¥
#define STR_RES_SNDOFF 24  // sndOff
#define STR_RES_RSTCTR 25  // rstCtr
#define STR_RES_NOTOFF 26  // notOff
#define STR_RES_OMNOFF 27  // omnOff
#define STR_RES_OMNION 28  // omniOn
#define STR_RES_MONOON 29  // monoOn
#define STR_RES_POLYON 30  // polyOn
#define STR_RES_SYSX__ 31  // sysx..
#define STR_RES__SYSX_ 32  // .sysx.
#define STR_RES___SYSX 33  // ..sysx
#define STR_RES_START 34  // start
#define STR_RES_STOP 35  // stop
#define STR_RES_CONT_ 36  // cont.
#define STR_RES_RESET 37  // reset
#define STR_RES_CHN 38  // chn
#define STR_RES_ALL 39  // all
#define STR_RES_REST 40  // rest
#define STR_RES_TIE 41  // tie
#define STR_RES_EXIT 42  // exit
#define STR_RES_OFF 43  // off
#define STR_RES_ON 44  // on
#define STR_RES_NO 45  // no
#define STR_RES_YES 46  // yes
#define STR_RES_XFE 47  // xFE
#define STR_RES_LET 48  // let
#define STR_RES_FLT 49  // flt
#define STR_RES_HLD 50  // hld
#define STR_RES__5S 51  // .5s
#define STR_RES__1S 52  // 1s
#define STR_RES__2S 53  // 2s
#define STR_RES_REC 54  // rec
#define STR_RES_DUB 55  // dub
#define STR_RES__TIE 56  // tie
#define STR_RES_RUN 57  // run
#define STR_RES_BPM 58  // bpm
#define STR_RES_GRV 59  // grv
#define STR_RES_AMT 60  // amt
#define STR_RES_TAP 61  // tap
#define STR_RES_SWG 62  // swg
#define STR_RES_SHF 63  // shf
#define STR_RES_PSH 64  // psh
#define STR_RES_LAG 65  // lag
#define STR_RES_HUM 66  // hum
#define STR_RES_MNK 67  // mnk
#define STR_RES_VAL 68  // val
#define STR_RES_NUM 69  // num
#define STR_RES_TYP 70  // typ
#define STR_RES_CC_ 71  // cc#
#define STR_RES_NRP 72  // nrp
#define STR_RES_MIN 73  // min
#define STR_RES_MAX 74  // max
#define STR_RES_LVL 75  // lvl
#define STR_RES_RST 76  // rst
#define STR_RES_SORRY___ 77  // sorry...
#define STR_RES_PERFECT_ 78  // perfect!
#define STR_RES_NOT_BAD_ 79  // not bad!
#define STR_RES_MOD 80  // mod
#define STR_RES_PTN 81  // ptn
#define STR_RES_EUC 82  // euc
#define STR_RES_INT 83  // int
#define STR_RES_EXT 84  // ext
#define STR_RES_CLK 85  // clk
#define STR_RES_PT1 86  // pt1
#define STR_RES_PT2 87  // pt2
#define STR_RES_PT3 88  // pt3
#define STR_RES_PT4 89  // pt4
#define STR_RES_CC1 90  // cc1
#define STR_RES_CC2 91  // cc2
#define STR_RES_CC3 92  // cc3
#define STR_RES_CC4 93  // cc4
#define STR_RES_CC5 94  // cc5
#define STR_RES_CC6 95  // cc6
#define STR_RES_CC7 96  // cc7
#define STR_RES_CC8 97  // cc8
#define STR_RES_INP 98  // inp
#define STR_RES_OUT 99  // out
#define STR_RES_CC_LFO_9 100  // cc lfo 9
#define STR_RES_CC_LFO10 101  // cc lfo10
#define STR_RES_CC_LFO11 102  // cc lfo11
#define STR_RES_CC_LFO12 103  // cc lfo12
#define STR_RES_CC_LFO13 104  // cc lfo13
#define STR_RES_NOT 105  // not
#define STR_RES_VEL 106  // vel
#define STR_RES_CC_LFO14 107  // cc lfo14
#define STR_RES_CC_LFO15 108  // cc lfo15
#define STR_RES_CC_LFO16 109  // cc lfo16
#define STR_RES_STK 110  // stk
#define STR_RES__VEL 111  // vel
#define STR_RES_OCT 112  // oct
#define STR_RES_DUR 113  // dur
#define STR_RES_LAT 114  // lat
#define STR_RES_DIV 115  // div
#define STR_RES_DEN 116  // den
#define STR_RES_128 117  // 128
#define STR_RES_96 118  // 96
#define STR_RES_64 119  // 64
#define STR_RES_58 120  // 58
#define STR_RES_52 121  // 52
#define STR_RES_46 122  // 46
#define STR_RES_40 123  // 40
#define STR_RES_34 124  // 34
#define STR_RES_28 125  // 28
#define STR_RES_22 126  // 22
#define STR_RES_16 127  // 16
#define STR_RES_14 128  // 14
#define STR_RES_13 129  // 13
#define STR_RES_12 130  // 12
#define STR_RES_11 131  // 11
#define STR_RES_10 132  // 10
#define STR_RES_9_6 133  // 9.6
#define STR_RES_9_3 134  // 9.3
#define STR_RES_9 135  // 9
#define STR_RES_8_6 136  // 8.6
#define STR_RES_8_3 137  // 8.3
#define STR_RES_8 138  // 8
#define STR_RES_7_6 139  // 7.6
#define STR_RES_7_3 140  // 7.3
#define STR_RES_7 141  // 7
#define STR_RES_6_6 142  // 6.6
#define STR_RES_6_3 143  // 6.3
#define STR_RES_6 144  // 6
#define STR_RES_5 145  // 5
#define STR_RES_4_1 146  // 4/1
#define STR_RES_3_1 147  // 3/1
#define STR_RES_2_1 148  // 2/1
#define STR_RES_3_2 149  // 3/2
#define STR_RES_1_1 150  // 1/1
#define STR_RES_3_4 151  // 3/4
#define STR_RES_2_3 152  // 2/3
#define STR_RES_1_2 153  // 1/2
#define STR_RES_3_8 154  // 3/8
#define STR_RES_1_3 155  // 1/3
#define STR_RES_1_4 156  // 1/4
#define STR_RES_1_6 157  // 1/6
#define STR_RES_1_8 158  // 1/8
#define STR_RES__12 159  // /12
#define STR_RES__16 160  // /16
#define STR_RES__24 161  // /24
#define STR_RES__32 162  // /32
#define STR_RES__48 163  // /48
#define STR_RES__96 164  // /96
#define STR_RES__C 165  // C
#define STR_RES_DB 166  // Db
#define STR_RES__D 167  // D
#define STR_RES_EB 168  // Eb
#define STR_RES__E 169  // E
#define STR_RES__F 170  // F
#define STR_RES_GB 171  // Gb
#define STR_RES__G 172  // G
#define STR_RES_AB 173  // Ab
#define STR_RES__A 174  // A
#define STR_RES_BB 175  // Bb
#define STR_RES__B 176  // B
#define STR_RES_KEY 177  // key
#define STR_RES__ 178  // 
#define STR_RES_STP 179  // stp
#define STR_RES_1 180  // 
#define STR_RES_2 181  // 
#define STR_RES_AM1 182  // am1
#define STR_RES_AM2 183  // am2
#define STR_RES_AM3 184  // am3
#define STR_RES_AM4 185  // am4
#define STR_RES_AM5 186  // am5
#define STR_RES_AM6 187  // am6
#define STR_RES_AM7 188  // am7
#define STR_RES_AM8 189  // am8
#define STR_RES_CE1 190  // ce1
#define STR_RES_CE2 191  // ce2
#define STR_RES_CE3 192  // ce3
#define STR_RES_CE4 193  // ce4
#define STR_RES_CE5 194  // ce5
#define STR_RES_CE6 195  // ce6
#define STR_RES_CE7 196  // ce7
#define STR_RES_CE8 197  // ce8
#define STR_RES_WF1 198  // wf1
#define STR_RES_WF2 199  // wf2
#define STR_RES_WF3 200  // wf3
#define STR_RES_WF4 201  // wf4
#define STR_RES_WF5 202  // wf5
#define STR_RES_WF6 203  // wf6
#define STR_RES_WF7 204  // wf7
#define STR_RES_WF8 205  // wf8
#define STR_RES_RT1 206  // rt1
#define STR_RES_RT2 207  // rt2
#define STR_RES_RT3 208  // rt3
#define STR_RES_RT4 209  // rt4
#define STR_RES_RT5 210  // rt5
#define STR_RES_RT6 211  // rt6
#define STR_RES_RT7 212  // rt7
#define STR_RES_RT8 213  // rt8
#define STR_RES_SY1 214  // sy1
#define STR_RES_SY2 215  // sy2
#define STR_RES_SY3 216  // sy3
#define STR_RES_SY4 217  // sy4
#define STR_RES_SY5 218  // sy5
#define STR_RES_SY6 219  // sy6
#define STR_RES_SY7 220  // sy7
#define STR_RES_SY8 221  // sy8
#define STR_RES_TRI 222  // tri
#define STR_RES_SQR 223  // sqr
#define STR_RES_RMP 224  // rmp
#define STR_RES_SIN 225  // sin
#define STR_RES_SI2 226  // si2
#define STR_RES_SI3 227  // si3
#define STR_RES_SI5 228  // si5
#define STR_RES_GG1 229  // gg1
#define STR_RES_GG2 230  // gg2
#define STR_RES_BT1 231  // bt1
#define STR_RES_BT2 232  // bt2
#define STR_RES_SP1 233  // sp1
#define STR_RES_SP2 234  // sp2
#define STR_RES_LP1 235  // lp1
#define STR_RES_LP2 236  // lp2
#define STR_RES_RS1 237  // rs1
#define STR_RES_RS2 238  // rs2
#define STR_RES_S_H 239  // s&h
#define STR_RES_PA 240  // pa
#define STR_RES_MA 241  // ma
#define STR_RES_NI 242  // ni
#define STR_RES_SA 243  // sa
#define STR_RES_RES 244  // res
#define STR_RES_FRE 245  // fre
#define STR_RES__NOT 246  // not
#define STR_RES_CHD 247  // chd
#define STR_RES_PRG 248  // prg
#define STR_RES_CH1 249  // ch1
#define STR_RES_CH2 250  // ch2
#define STR_RES_CH3 251  // ch3
#define STR_RES_CH4 252  // ch4
#define STR_RES_CH5 253  // ch5
#define STR_RES_CH6 254  // ch6
#define STR_RES_CH7 255  // ch7
#define STR_RES_CH8 256  // ch8
#define LUT_RES_ARPEGGIATOR_PATTERNS 0
#define LUT_RES_ARPEGGIATOR_PATTERNS_SIZE 22
#define LUT_RES_DRUM_PATTERNS 1
#define LUT_RES_DRUM_PATTERNS_SIZE 48
#define LUT_RES_GROOVE_SWING 2
#define LUT_RES_GROOVE_SWING_SIZE 16
#define LUT_RES_GROOVE_SHUFFLE 3
#define LUT_RES_GROOVE_SHUFFLE_SIZE 16
#define LUT_RES_GROOVE_PUSH 4
#define LUT_RES_GROOVE_PUSH_SIZE 16
#define LUT_RES_GROOVE_LAG 5
#define LUT_RES_GROOVE_LAG_SIZE 16
#define LUT_RES_GROOVE_HUMAN 6
#define LUT_RES_GROOVE_HUMAN_SIZE 16
#define LUT_RES_GROOVE_MONKEY 7
#define LUT_RES_GROOVE_MONKEY_SIZE 16
#define LUT_RES_EUCLIDIAN_PATTERNS 8
#define LUT_RES_EUCLIDIAN_PATTERNS_SIZE 144
#define LUT_RES_SCALE_0 9
#define LUT_RES_SCALE_0_SIZE 12
#define LUT_RES_SCALE_1 10
#define LUT_RES_SCALE_1_SIZE 12
#define LUT_RES_SCALE_2 11
#define LUT_RES_SCALE_2_SIZE 12
#define LUT_RES_SCALE_3 12
#define LUT_RES_SCALE_3_SIZE 12
#define LUT_RES_SCALE_4 13
#define LUT_RES_SCALE_4_SIZE 12
#define LUT_RES_SCALE_5 14
#define LUT_RES_SCALE_5_SIZE 12
#define LUT_RES_SCALE_6 15
#define LUT_RES_SCALE_6_SIZE 12
#define LUT_RES_SCALE_7 16
#define LUT_RES_SCALE_7_SIZE 12
#define LUT_RES_SCALE_8 17
#define LUT_RES_SCALE_8_SIZE 12
#define LUT_RES_SCALE_9 18
#define LUT_RES_SCALE_9_SIZE 12
#define LUT_RES_SCALE_10 19
#define LUT_RES_SCALE_10_SIZE 12
#define LUT_RES_SCALE_11 20
#define LUT_RES_SCALE_11_SIZE 12
#define LUT_RES_SCALE_12 21
#define LUT_RES_SCALE_12_SIZE 12
#define LUT_RES_SCALE_13 22
#define LUT_RES_SCALE_13_SIZE 12
#define LUT_RES_SCALE_14 23
#define LUT_RES_SCALE_14_SIZE 12
#define LUT_RES_SCALE_15 24
#define LUT_RES_SCALE_15_SIZE 12
#define LUT_RES_SCALE_16 25
#define LUT_RES_SCALE_16_SIZE 12
#define LUT_RES_SCALE_17 26
#define LUT_RES_SCALE_17_SIZE 12
#define LUT_RES_SCALE_18 27
#define LUT_RES_SCALE_18_SIZE 12
#define LUT_RES_SCALE_19 28
#define LUT_RES_SCALE_19_SIZE 12
#define LUT_RES_SCALE_20 29
#define LUT_RES_SCALE_20_SIZE 12
#define LUT_RES_SCALE_21 30
#define LUT_RES_SCALE_21_SIZE 12
#define LUT_RES_SCALE_22 31
#define LUT_RES_SCALE_22_SIZE 12
#define LUT_RES_SCALE_23 32
#define LUT_RES_SCALE_23_SIZE 12
#define LUT_RES_SCALE_24 33
#define LUT_RES_SCALE_24_SIZE 12
#define LUT_RES_INCREMENTS 34
#define LUT_RES_INCREMENTS_SIZE 48
#define CHR_RES_DIGITS_10 0
#define CHR_RES_DIGITS_10_SIZE 56
#define CHR_RES_SEQUENCER_ICONS 1
#define CHR_RES_SEQUENCER_ICONS_SIZE 32
#define WAV_RES_LFO_WAVEFORMS 0
#define WAV_RES_LFO_WAVEFORMS_SIZE 2193
typedef avrlib::ResourcesManager<
    ResourceId,
    avrlib::ResourcesTables<
        string_table,
        lookup_table_table> > ResourcesManager; 

}  // namespace midipal

#endif  // MIDIPAL_RESOURCES_H_
