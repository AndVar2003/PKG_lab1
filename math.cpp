#include "math.h"
#include <cmath>
double static min(double, double, double);
double static max(double, double, double);
double static Hue_to_RGB(double,double,double);
math::math()
{
    HEX = "000000";
}

void math::setRGB(double r,double g,double b)
{
    rgb[0] = double(r);
    rgb[1] = double(g);
    rgb[2] = double(b);
    RGBToHEX();
    RGBToCMYK();
    RGBToHSV();
    RGBToHSL();
    RGBToXYZ();
    XYZToLAB();
}
void math::setCMYK(double c,double m,double y,double k)
{
    cmyk[0] = double(c)/100;
    cmyk[1] = double(m)/100;
    cmyk[2] = double(y)/100;
    cmyk[3] = double(k)/100;
    CMYKToRGB();
    RGBToHEX();
    RGBToHSV();
    RGBToHSL();
    RGBToXYZ();
    XYZToLAB();
}
void math::setHSV(double h,double s,double v)
{
    hsv[0] = double(h) / 360;
    hsv[1] = double(s) / 100;
    hsv[2] = double(v) / 100;
    HSVToRGB();
    RGBToHEX();
    RGBToCMYK();
    RGBToHSL();
    RGBToXYZ();
    XYZToLAB();
}
void math::setHSL(double h,double s,double l)
{
    hsl[0] = double(h) / 360;
    hsl[1] = double(s) / 100;
    hsl[2] = double(l) / 100;
    HSLToRGB();
    RGBToHEX();
    RGBToHSV();
    RGBToCMYK();
    RGBToXYZ();
    XYZToLAB();
}
void math::setXYZ(double x,double y,double z)
{
    xyz[0]=double(x);
    xyz[1]=double(y);
    xyz[2]=double(z);
    XYZToLAB();
    XYZToRGB();
    RGBToHEX();
    RGBToCMYK();
    RGBToHSV();
    RGBToHSL();
}
void math::setLAB(double l,double a,double b)
{
    lab[0]=double(l);
    lab[1]=double(a);
    lab[2]=double(b);
    LABToXYZ();
    XYZToRGB();
    RGBToHEX();
    RGBToCMYK();
    RGBToHSV();
    RGBToHSL();
}
void math::setHEX(QString hexstr)
{
    HEX = hexstr;
    HEXToRGB();
    RGBToCMYK();
    RGBToHSV();
    RGBToHSL();
    RGBToXYZ();
    XYZToLAB();
}

double math::getR_rgb()const
{
    return double(rgb[0]);
}
double math::getG_rgb()const
{
    return double(rgb[1]);
}
double math::getB_rgb()const
{
    return double(rgb[2]);
}

double math::getC_cmyk()const
{
    return double(cmyk[0])*100;
}
double math::getM_cmyk()const
{
    return double(cmyk[1])*100;
}
double math::getY_cmyk()const
{
    return double(cmyk[2])*100;
}
double math::getK_cmyk()const
{
    return double(cmyk[3])*100;
}
double math::getH_hsv()const
{
    return double(hsv[0])*360;
}
double math::getS_hsv()const
{
    return double(hsv[1])*100;
}
double math::getV_hsv()const
{
    return double(hsv[2])*100;
}

double math::getH_hsl()const
{
    return double(hsl[0])*360;
}
double math::getL_hsl()const
{
    return double(hsl[2])*100;
}
double math::getS_hsl()const
{
    return double(hsl[1])*100;
}

double math::getX_xyz()const
{
    return double(xyz[0]);
}
double math::getY_xyz()const
{
    return double(xyz[1]);
}
double math::getZ_xyz()const
{
    return double(xyz[2]);
}

double math::getL_lab()const
{
    return double(lab[0]);
}
double math::getA_lab()const
{
    return double(lab[1]);
}
double math::getB_lab()const
{
    return double(lab[2]);
}

QString math::getHEX()const
{
    return HEX;
}

double static min(double a, double b, double c)
{
    if(a < b && a < c)
    {
        return a;
    }
    else if(b < c)
    {
        return b;
    }
    else
    {
        return c;
    }

}
double static max(double a, double b, double c)
{
    if(a > b && a > c)
    {
        return a;
    }
    else if(b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}
double static Hue_to_RGB(double val_1,double val_2,double valH )
{
   if (valH < 0)
       valH += 1;
   if(valH > 1)
       valH -= 1;
   if (( 6 * valH ) < 1)
       return ( val_1 + ( val_2 - val_1 ) * 6 * valH );
   if (( 2 * valH ) < 1)
       return ( val_2 );
   if (( 3 * valH ) < 2)
       return ( val_1 + ( val_2 - val_1 ) * ( ( 2 / 3 ) - valH ) * 6 );
   return ( val_1 );
}

void math::RGBToHEX()
{
    QString fir = QString::number(int(rgb[0]),16);
    if (fir.length() == 1)
        fir = "0"+ fir;
    QString sec = QString::number(int(rgb[1]),16);
    if (sec.length() == 1)
        sec = "0"+ sec;
    QString thr = QString::number(int(rgb[2]),16);
    if (thr.length() == 1)
        thr = "0"+ thr;
    HEX = fir + sec + thr;
}
void math::RGBToCMYK()
{
    if ((1- rgb[0]/double(255) < 1 - rgb[1]/double(255)) && (1- rgb[0]/double(255) < 1 - rgb[2]/double(255)))
    {
        cmyk[3] = 1 - rgb[0]/double(255);
    }
    else if (1 - rgb[1]/double(255) < 1 - rgb[2]/double(255))
    {
        cmyk[3] = 1 - rgb[1]/double(255);
    }
    else
    {
        cmyk[3] = 1 - rgb[2]/double(255);
    }
    cmyk[0] = (1-rgb[0]/double(255) - cmyk[3])/(1 - cmyk[3]);
    cmyk[1] = (1-rgb[1]/double(255) - cmyk[3])/(1 - cmyk[3]);
    cmyk[2] = (1-rgb[2]/double(255) - cmyk[3])/(1 - cmyk[3]);
}
void math::RGBToHSV()
{
    double r = ( rgb[0] / double(255) );
    double g = ( rgb[1] / double(255) );
    double b = ( rgb[2] / double(255) );

    double max_val = min(r, g, b);
    double min_val = max(r, g, b);
    double del_Max = max_val - min_val;

    hsv[2] = max_val;

    if (del_Max == 0)
    {
        hsv[0] = 0;
        hsv[1] = 0;
    }
    else
    {
       hsv[1] = del_Max / max_val;

       double del_r = ( ( ( max_val - r ) / double(6) ) + ( del_Max / double(2) ) ) / del_Max;
       double del_g = ( ( ( max_val - g ) / double(6) ) + ( del_Max / double(2) ) ) / del_Max;
       double del_b = ( ( ( max_val - b ) / double(6) ) + ( del_Max / double(2) ) ) / del_Max;

       if( r == max_val )
           hsv[0] = del_b - del_g;
       else if( g == max_val )
           hsv[0] = ( double(1) / double(3) ) + del_r - del_b;
       else if( b == max_val )
           hsv[0] = ( double(2) / double(3) ) + del_g - del_r;
        if ( hsv[0] < 0 )
            hsv[0] += 1;
        if ( hsv[0] > 1 )
            hsv[0] -= 1;
    }
}
void math::RGBToHSL()
{
    double r = ( rgb[0] / 255 );
    double g = ( rgb[1] / 255 );
    double b = ( rgb[2] / 255 );

    double min_value = min(r, g, b);
    double max_value = max(b, g, r);
    double del_Max = max_value - min_value;

    hsl[1] = ( max_value + min_value )/ double(2);

    if ( del_Max == 0 )
    {
        hsl[0] = 0;
        hsl[2] = 0;
    }
    else
    {
       if ( hsl[1] < 0.5 )
            hsl[2] = del_Max / ( max_value + min_value );
       else
            hsl[2] = del_Max / ( 2 - max_value - min_value );

       double del_R = ( ( ( max_value - r ) / double(6) ) + ( del_Max / double(2) ) ) / del_Max;
       double del_G = ( ( ( max_value - g ) / double(6) ) + ( del_Max / double(2) ) ) / del_Max;
       double del_B = ( ( ( max_value - b ) / double(6) ) + ( del_Max / double(2) ) ) / del_Max;

       if(r == max_value)
            hsl[0] = del_B - del_G;
       else if (g == max_value)
            hsl[0] = double(1) / double(3) + del_R - del_B;
       else if(b == max_value)
            hsl[0] = double(2) / double(3) + del_G - del_R;

        if ( hsl[0] < 0 )
            hsl[0] += 1;
        if ( hsl[0] > 1 )
            hsl[0] -= 1;
    }
}
void math::RGBToXYZ()
{
    double r = rgb[0] / double(255);
    double g = rgb[1] / double(255);
    double b = rgb[2] / double(255);

    if (r > 0.04045)
        r = pow((( r + 0.055 ) / 1.055), 2.4);
    else
        r = r / 12.92;
    if (g > 0.04045)
        g = pow((( g + 0.055 ) / 1.055), 2.4);
    else
        g = g / 12.92;
    if ( b > 0.04045 )
        b = pow(((b + 0.055 ) / 1.055), 2.4);
    else
        b = b / 12.92;

    r = r * 100;
    g = g * 100;
    b = b * 100;

    xyz[0] = r * 0.4124 + g * 0.3576 + b * 0.1805;
    xyz[1] = r * 0.2126 + g * 0.7152 + b * 0.0722;
    xyz[2] = r * 0.0193 + g * 0.1192 + b * 0.9505;
    if (xyz[0] < 0)
        lab[0] = 0;
    if (xyz[0] > 95)
        lab[0] = 95;
    if (xyz[1]< 0)
        lab[0] = 0;
    if (xyz[1]> 100)
        lab[0] = 100;
    if (xyz[2]< 0)
        lab[0] = 0;
    if (xyz[2]> 108)
        lab[0] = 108;
}

void math::XYZToLAB()
{
    double x = xyz[0] / 95.047;
    double y = xyz[1] / 100;
    double z = xyz[2] / 108.883;

    if ( x > 0.008856 )
        x = cbrt(x);
    else
        x = ( 7.787 * x ) + ( double(16) / double(116) );
    if ( y > 0.008856 )
        y = cbrt(y);
    else
        y = ( 7.787 * y ) + ( double(16) / double(116) );
    if ( z > 0.008856 )
        z = cbrt(z);
    else
        z = ( 7.787 * z ) + ( double(16) / double(116) );

    lab[0] = ( 116 * y ) - 16;
    if (lab[0] < 0)
        lab[0] = 0;
    if (lab[0] > 100)
        lab[0] = 100;
    lab[1] = 500 * ( x - y );
    if (lab[1] < -128)
        lab[1] = -128;
    if (lab[1] > 128)
        lab[1] = 128;
    lab[2] = 200 * ( y - z );
    if (lab[2] < -128)
        lab[2] = -128;
    if (lab[2] > 128)
        lab[2] = 128;
}
void math::CMYKToRGB()
{
    rgb[0]= 255*(1 - cmyk[0])*(1 - cmyk[3]);
    rgb[1]= 255*(1 - cmyk[1])*(1 - cmyk[3]);
    rgb[2]= 255*(1 - cmyk[2])*(1 - cmyk[3]);
}
void math::HSVToRGB()
{
    if (hsv[1] == 0)
    {
       rgb[0] = hsv[2] * 255;
       rgb[1] = hsv[2] * 255;
       rgb[2] = hsv[2] * 255;
    }
    else
    {
       double H = hsv[0] * 6;
       if (H == 6)
           H = 0;
       int var_i = (int)H;
       double var_1 = hsv[2] * (1 - hsv[1] );
       double var_2 = hsv[2] * (1 - hsv[1] * (H - var_i ));
       double var_3 = hsv[2] * (1 - hsv[1] * (1 - ( H - var_i )));
    double var_r, var_g, var_b;

       if      ( var_i == 0 ) {
           var_r = hsv[2];
           var_g = var_3;
           var_b = var_1;
       }
       else if ( var_i == 1 ) {
           var_r = var_2;
           var_g = hsv[2];
           var_b = var_1;
       }
       else if ( var_i == 2 ) {
           var_r = var_1;
           var_g = hsv[2];
           var_b = var_3;
       }
       else if ( var_i == 3 ) {
           var_r = var_1;
           var_g = var_2;
           var_b = hsv[2];
       }
       else if ( var_i == 4 ) {
           var_r = var_3;
           var_g = var_1;
           var_b = hsv[2];
       }
       else {
           var_r = hsv[2];
           var_g = var_1;
           var_b = var_2;
       }

       rgb[0] = var_r * 255;
       rgb[1] = var_g * 255;
       rgb[2] = var_b * 255;
    }
    if(rgb[0]> 255)
        rgb[0] = 255;
    if(rgb[1]> 255)
        rgb[1] = 255;
    if(rgb[2]> 255)
        rgb[2] = 255;
}
void math::HSLToRGB()
{
    if ( hsl[1] == 0 )
    {

       rgb[0] = hsl[2] * 255;
       rgb[1] = hsl[2] * 255;
       rgb[2] = hsl[2] * 255;
    }
    else
    {
       double val_2;
       if ( hsl[2] < 0.5 )
            val_2 = hsl[2] * ( 1 + hsl[1] );
       else
            val_2 = ( hsl[1] + hsl[2] ) - ( hsl[2] * hsl[1] );

       double val_1 = 2 * hsl[2] - val_2;

       rgb[0] = 255 * Hue_to_RGB( val_1, val_2, hsl[0] + ( 1 / 3 ));
       rgb[1] = 255 * Hue_to_RGB( val_1, val_2, hsl[0]);
       rgb[2] = 255 * Hue_to_RGB( val_1, val_2, hsl[0] - ( 1 / 3 ));
    }
    if(rgb[0]> 255)
        rgb[0] = 255;
    if(rgb[1]> 255)
        rgb[1] = 255;
    if(rgb[2]> 255)
        rgb[2] = 255;
}
void math::XYZToRGB()
{
    double x = double(xyz[0]) / double(100);
    double y = double(xyz[1]) / double(100);
    double z = double(xyz[2]) / double(100);

    double r = x *  3.2406 + y * -1.5372 + z * -0.4986;
    double g = x * -0.9689 + y *  1.8758 + z *  0.0415;
    double b = x *  0.0557 + y * -0.2040 + z *  1.0570;

    if (r > 0.0031308)
            r = 1.055 *  pow(r, 1 / 2.4 ) - 0.055;
    else
            r = 12.92 * r;
    if ( g > 0.0031308 )
            g = 1.055 * pow(g, 1 / 2.4) - 0.055;
    else
            g = 12.92 * g;
    if ( b > 0.0031308 )
            b = 1.055 * pow(b, 1 / 2.4) - 0.055;
    else
            b = 12.92 * b;

    rgb[0] = r * 255;
    rgb[1] = g * 255;
    rgb[2] = b * 255;
    if(rgb[0]> 255)
        rgb[0] = 255;
    if(rgb[0]< 0)
        rgb[0] = 0;
    if(rgb[1]> 255)
        rgb[1] = 255;
    if(rgb[1]< 0)
        rgb[1] = 0;
    if(rgb[2]> 255)
        rgb[2] = 255;
    if(rgb[2]< 0)
        rgb[2] = 0;
}
void math::LABToXYZ()
{
    double y = ( lab[0] + 16 ) / double(116);
    double x = lab[1] / double(500) + y;
    double z = y - lab[2] / double(200);

    if ( pow(y,3)  > 0.008856 )
        y = pow(y,3);
    else
        y = ( y - double(16) / double(116) ) / 7.787;
    if ( pow(x,3)  > 0.008856 )
        x = pow(x,3);
    else
        x = ( x - double(16) / double(116) ) / 7.787;
    if ( pow(z,3)  > 0.008856 )
        z = pow(z,3);
    else
        z = ( z - double(16) / double(116) ) / 7.787;

    xyz[0] = x * 95.047;
    xyz[1] = y * 100;
    xyz[2] = z * 108.883;
    if (xyz[0] < 0)
        xyz[0] = 0;
    if (xyz[0] > 95.047)
        xyz[0] = 95.047;
    if (xyz[1]< 0)
        xyz[1] = 0;
    if (xyz[1]> 100)
        xyz[1] = 100;
    if (xyz[2]< 0)
        xyz[2] = 0;
    if (xyz[2]> 108.883)
        xyz[2] = 108.883;
}

void math::HEXToRGB()
{
    bool ok;
    QString buffer1(HEX[0]);
    buffer1 += HEX[1];
    QString buffer2(HEX[2]);
    buffer2 += HEX[3];
    QString buffer3(HEX[4]);
    buffer3 += HEX[5];
    rgb[0]=buffer1.toInt(&ok,16);
    rgb[1]=buffer2.toInt(&ok,16);
    rgb[2]=buffer3.toInt(&ok,16);
}
