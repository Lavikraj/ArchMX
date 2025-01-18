#include<vec3.h>
#include<assert.h>

namespace arcmx {

    class particle{

        public:
            vec3 position;
            vec3 velocity;
            vec3 acceleration;

            /**
            * Holds the amount of damping applied to linear
            * motion. Damping is required to remove energy added
            * through numerical instability in the integrator.
            */
            real damping;

            /* storing inverse mass 
                instead of mass because:-
                * integration is simpler and because in real-time
                * simulation it is more useful to have objects with
                * infinite mass (immovable) than zero mass
                * (completely unstable in numerical simulation).
            */
            real inverseMass;

            /**
            * Integrates the particle forward in time by the given amount.
            * This function uses a Newton-Euler integration method, which is a
            * linear approximation of the correct integral. For this reason it
            * may be inaccurate in some cases.
            */
            void integrate(real duration, vec3 forceAccm){

                assert(duration > 0.0);

                // update linear position
                position += velocity * duration;

                // workout the accelration from the force
                vec3 resultingAcc = acceleration;
                resultingAcc += forceAccm * inverseMass;

                // update linear velocity from accelration;
                velocity += resultingAcc * duration;

                // impose drag
                velocity *= real_pow(damping,duration);
           };
    };
}