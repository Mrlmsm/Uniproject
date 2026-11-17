#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main (int argc, char** argv){
	char *encoded = "Kn\"eqtuq\"hqtpkueg\"wp)kpvtqfw|kqpg\"cn\"nkpiwciikq\"fk\"rtqitcooc|kqpg\"E\"g\"cnnc\"rtqitcooc|kqpg\"korgtcvkxc0\"Wp\"pwogtq\"eqpukuvgpvg\"fk\"qtg\"gb\"wvknk||cvq\"rgt\"uxqnigtg\"gugtekvc|kqpk\"kp\"ncdqtcvqtkq\"hkpcnk||cvg\"c\"rtgpfgtg\"eqphkfgp|c\"eqp\"kn\"nkpiwciikq\"vtcokvg\"nc\"tgcnk||c|kqpg\"fk\"rtqitcook\"kp\"nkpiwciikq\"E0";

	for(size_t i = 0; encoded[i] != '\0'; i++){
		char c = ((unsigned char)encoded[i] - 2);
		printf("%c", c);
	}
	return 0;
	
}
