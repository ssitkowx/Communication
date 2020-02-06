#include "Communication.h"

class CommExample : public Communication
{
	protected:
		void send    (void) {}
		void receive (void) {}
};

int main (void)
{
	CommExample comm;
}
