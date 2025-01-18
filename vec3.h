#include<precision.h>

namespace Peter {

    struct vec3{
        
        public:
            real x;
            real y;
            real z;

        private:

            real pad;

        public:

            vec3(const real i = 0, const real j = 0, const real k = 0) : x(i),y(j),z(k){}


            // Operations with other vectors
            vec3 operator+ (const vec3 & other) const {

                return vec3(x + other.x , y + other.y , z + other.z);
            }
            vec3 operator- (const vec3 & other) const {

                return vec3(x - other.x , y - other.y , z - other.z);
            }
            
            void operator+= (const vec3 & other){

                x += other.x; y += other.y; z += other.z;
            }
            void operator-= (const vec3 & other){

                x -= other.x; y -= other.y; z -= other.z;
            }


            // Opreation with other scalar
            vec3 operator* (const real scalar) const {

                return vec3(x * scalar , y * scalar , z * scalar);
            }
            void operator*= (const real scalar){

                x *= scalar; y *= scalar; z *= scalar;
            }


            // Magnitude
            real magnitude() const {

                return real_sqrt(x*x + y*y + z*z);
            }
            real squareMagnitude() const {

                return (x*x + y*y + z*z);
            }


            // Normalization
            void normalize(){

                real d = magnitude();
                
                if(d > 0){
                    (*this) *= ((real)1) / d;
                }

                /* if(d > 0){
                    d = ((real)1) / d;
                    x = x * d;
                    y = y * d;
                    z = z * d;
                } */
            }


            // Component Product
            vec3 componentProduct(const vec3& v){

                return vec3(x*v.x, y*v.y, z*v.y);
            }
            void componentProductUpdate(const vec3& v){

                x *= v.x;
                y *= v.y;
                z *= v.z;
            }
    

            //Product
            real scalarProduct(const vec3& v) const {

                return x*v.x + y*v.y + z*v.z;
            }
            real operator*(const vec3& other) const {

                return x*other.x + y*other.y + z*other.z;
            }
            
            vec3 vectorProduct(const vec3& v) const {
                
                return vec3(y*v.z - z*v.y , z*v.x - x*v.z , x*v.y - y*v.x);
            }
            void operator%= (const vec3& v){

                x = y*v.z - z*v.y;
                y = z*v.x - x*v.z;
                z = x*v.y - y*v.x;
            }
            vec3 operator% (const vec3& v) const{

                return vec3(y*v.z - z*v.y , z*v.x - x*v.z , x*v.y - y*v.x);
            }
    };
}
