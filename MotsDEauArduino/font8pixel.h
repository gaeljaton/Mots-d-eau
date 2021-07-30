//const byte data[] = {  //ABCD...
//  0x00, 0x00, 0x00, 0x00,
//  0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, //damier x 8
//  //arabesque x 4
//  0x7F, 0x40, 0x5F, 0x51, 0x5D, 0x45, 0x7D, 0x01, 0x7F, 0x40, 0x5F, 0x51, 0x5D, 0x45, 0x7D, 0x01, 0x7F, 0x40, 0x5F, 0x51, 0x5D, 0x45, 0x7D, 0x01, 0x7F, 0x40, 0x5F, 0x51, 0x5D, 0x45, 0x7D, 0x01,
//  0x00, 0x00, 0x00, 0x00,
//  //ABCD...Z
//  0x80, 0xE0, 0xBC, 0x23, 0xBC, 0xE0, 0x80, 0x00,
//  0x81, 0xFF, 0x89, 0x89, 0x89, 0x76, 0x00,
//  0x3C, 0x42, 0x81, 0x81, 0x81, 0x42, 0x00,
//  0x81, 0xFF, 0x81, 0x81, 0x81, 0x42, 0x3C, 0x00,
//  0x81, 0xFF, 0x89, 0x9D, 0x81, 0xC3, 0x00,
//  0x81, 0xFF, 0x89, 0x1D, 0x01, 0x03, 0x00,
//  0x3C, 0x42, 0x81, 0x81, 0x91, 0x73, 0x10, 0x81, 0xFF, 0x89, 0x08, 0x89, 0xFF, 0x81, 0x00,
//  0x81, 0xFF, 0x81, 0x00,
//  0x40, 0x80, 0x81, 0x7F, 0x01, 0x00,
//  0x81, 0xFF, 0x89, 0x14, 0xA3, 0xC1, 0x81, 0x00, 0x00,
//  0x81, 0xFF, 0x81, 0x80, 0xC0, 0x00, 0x00, 0x81, 0xFF, 0x87, 0x38, 0x40, 0x38, 0x87,
//  0xFF, 0x81, 0x00, 0x81, 0xFF, 0x84, 0x18, 0x21, 0xFF, 0x81, 0x00, 0x3C, 0x42, 0x81, 0x81, 0x81,
//  0x42, 0x3C, 0x00, 0x81, 0xFF, 0x91, 0x11, 0x11, 0x0E, 0x00, 0x3C, 0x42, 0x81, 0xA1, 0xA1, 0x42,
//  0xBC, 0x00, 0x81, 0xFF, 0x89, 0x19, 0x69, 0x86, 0x80, 0x00, 0xC6, 0x89, 0x91, 0x63, 0x00, 0x03,
//  0x01, 0x81, 0xFF, 0x81, 0x01, 0x03, 0x00, 0x01, 0x7F, 0x81, 0x80, 0x81, 0x7F, 0x01, 0x00, 0x01,
//  0x07, 0x39, 0xC0, 0x39, 0x07, 0x01, 0x00, 0x01, 0x07, 0x39, 0xC0, 0x31, 0x0F, 0x31, 0xC0, 0x39,
//  0x07, 0x01, 0x00, 0x81, 0xC3, 0xA5, 0x18, 0xA5, 0xC3, 0x81, 0x00, 0x01, 0x03, 0x8D, 0xF0, 0x8D,
//  0x03, 0x01, 0x00, 0xC3, 0xA1, 0x99, 0x85, 0xC3,
//  0x00, 0x00, 0x00, 0x00,
//};

const byte font[100][8] = {
  {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, // 32 first ASCII
  {0},//  32 space
  { 191
    , 0
  },// 33 !
  { 7
    , 0
    , 7
    , 0
  },// 34 "
  { 40
    , 124
    , 40
    , 124
    , 40
    , 0
  },// 35 #
  { 255
    , 1
    , 255
    , 128
    , 255
    , 1
    , 255
    , 128
  },// 36 $ = LACETS
  { 66
    , 37
    , 18
    , 72
    , 164
    , 66
    , 0
  },// 37 %
  {28
, 62
, 126
, 252
, 126
, 62
, 28
, 0
},// 38 & = coeur
  { 12
    , 3
    , 0
  },// 39 '
  { 60
    , 195
    , 0
  },// 40 (
  { 195
    , 60
    , 0
  },// 41 )
  { 170
    , 85
    , 170
    , 85
    , 170
    , 85
    , 170
    , 85
  },// 42 * = DAMIER
  { 24
    , 24
    , 126
    , 126
    , 24
    , 24
    , 0
  },// 43 +
  { 238
    , 34
    , 187
    , 136
    , 238
    , 34
    , 187
    , 136
  },// 44 , = serpentin
  { 24
    , 24
    , 24
    , 24
    , 24
    , 24
    , 0
  },// 45 -
  { 192
    , 192
    , 0
  },// 46 .
  { 192
    , 48
    , 12
    , 3
    , 0
  },// 47 /
  { 126
    , 129
    , 145
    , 129
    , 126
    , 0
  },// 48 0
  { 128
    , 129
    , 255
    , 128
    , 128
    , 0
  },// 49 1
  { 194
    , 161
    , 145
    , 137
    , 134
    , 0
  },// 50 2
  { 66
    , 129
    , 137
    , 137
    , 118
    , 0
  },// 51 3
  { 48
    , 40
    , 38
    , 161
    , 255
    , 160
  },// 52 4
  { 64
    , 143
    , 137
    , 137
    , 113
    , 0
  },// 53 5
  { 124
    , 138
    , 137
    , 137
    , 113
    , 0
  },// 54 6
  { 3
    , 1
    , 193
    , 57
    , 7
    , 0
  },// 55 7
  { 118
    , 137
    , 137
    , 137
    , 118
    , 0
  },// 56 8
  { 142
    , 145
    , 145
    , 81
    , 62
    , 0
  },// 57 9
  { 102
    , 102
    , 0
  },// 58 :
  {},// 59 ;
  { 16
    , 40
    , 68
    , 130
    , 0
  },// 60 <
  { 40
    , 40
    , 40
    , 40
    , 40
    , 0
  },// 61 =
  { 130
    , 68
    , 40
    , 16
    , 0
  },// 62 >
  { 6
    , 1
    , 177
    , 9
    , 6
    , 0
  },// 63 ?
  { 254
    , 2
    , 250
    , 138
    , 186
    , 162
    , 190
    , 128
  },// 64 @
  { 128
    , 224
    , 188
    , 35
    , 188
    , 224
    , 128
    , 0
  },// 65 A
  { 129
    , 255
    , 137
    , 137
    , 137
    , 118
    , 0
  },// 66 B
  { 60
    , 66
    , 129
    , 129
    , 129
    , 66
    , 0
  },// 67 C
  { 129
    , 255
    , 129
    , 129
    , 129
    , 66
    , 60
    , 0
  },// 68 D
  { 129
    , 255
    , 137
    , 157
    , 129
    , 195
    , 0
  },// 69 E
  { 129
    , 255
    , 137
    , 29
    , 1
    , 3
    , 0
  },// 70 F
  { 60
    , 66
    , 129
    , 129
    , 145
    , 115
    , 16
    , 0
  },// 71 G
  { 129
    , 255
    , 137
    , 8
    , 137
    , 255
    , 129
    , 0
  },// 72 H
  { 129
    , 255
    , 129
    , 0
  },// 73 I
  { 64
    , 128
    , 129
    , 127
    , 1
    , 0
  },// 74 J
  { 129
    , 255
    , 137
    , 20
    , 163
    , 193
    , 129
    , 0
  },// 75 K
  { 129
    , 255
    , 129
    , 128
    , 192
    , 0
  },// 76 L
  { 129
    , 255
    , 135
    , 24
    , 135
    , 255
    , 129
    , 0
  },// 77 M
  { 129
    , 255
    , 132
    , 24
    , 33
    , 255
    , 129
    , 0
  },// 78 N
  { 60
    , 66
    , 129
    // , 129
    , 129
    , 66
    , 60
    , 0
  },// 79 O
  { 129
    , 255
    , 145
    , 17
    , 17
    , 14
    , 0
  },// 80 P
  { 60
    , 66
    , 129
    , 161
    , 161
    , 66
    , 188
    , 0
  },// 81 Q
  { 129
    , 255
    , 137
    , 25
    , 105
    , 134
    , 128
    , 0
  },// 82 R
  { 198
    , 137
    , 145
    , 99
    , 0
  },// 83 S
  { 3
    , 1
    , 129
    , 255
    , 129
    , 1
    , 3
    , 0
  },// 84 T
  { 1
    , 127
    , 129
    , 128
    , 129
    , 127
    , 1
    , 0
  },// 85 U
  { 1
    , 7
    , 57
    , 192
    , 57
    , 7
    , 1
    , 0
  },// 86 V
  { 1
    , 127
    , 129
    , 112
    , 129
    , 127
    , 1
    , 0
  },// 87 W
  { 129
    , 195
    , 165
    , 24
    , 165
    , 195
    , 129
    , 0
  },// 88 X
  { 1
    , 3
    , 141
    , 240
    , 141
    , 3
    , 1
    , 0
  },// 89 Y
  { 195
    , 161
    , 153
    , 133
    , 195
    , 0
  },// 90 Z
  { 255
    , 129
    , 0
  },// 91 [
  { 3
    , 12
    , 48
    , 192
    , 0
  },// 92 '\'
  { 129
    , 255
    , 0
  },// 93 ]
  { 4
    , 2
    , 1
    , 2
    , 4
    , 0
  },// 94 ^
  { 128
    , 128
    , 128
    , 128
    , 128
    , 0
  },// 95 _
{ 60
, 94
, 155
, 159
, 159
, 155
, 94
, 60
},// 96 ` = smilley
{ 152
, 92
, 182
, 95
, 95
, 182
, 92
, 152
},// 97 a = space invader 1
{ 88
, 188
, 22
, 63
, 63
, 22
, 188
, 88
},// 98 b = space invader 2
{ 184
, 125
, 54
, 60
, 60
, 54
, 125
, 184
}// 99 c = space invader 3




};
