#pragma once

#include "EloquentCounter.h"


namespace Eloquent {

    #define attachInterruptCounter(counter) attachInterrupt(counter.pin(),[]() { counter++; }, counter.mode());

    class InterruptCounter : public Counter {

        public:
            InterruptCounter(uint8_t interruptPin, uint8_t mode = CHANGE) {
                _pin = interruptPin;
                _mode = mode;
            }

            /**
             * Get interrupt pin 
             */
            uint8_t pin() {
                return _pin;
            }

            /**
             * Get interrupt mode
             */
            uint8_t mode() {
                return _mode;
            }

        protected: 
            uint8_t _pin;
            uint8_t _mode;
    };
}