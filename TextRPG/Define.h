#pragma once

#define SafeDelete(p) if(p) {delete p; p = nullptr;}
#define SafeDeleteARR(p) if(p) {delete[] p; p = nullptr;}

#define PURE =0