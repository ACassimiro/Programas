#include <termios.h>

int main(){

	struct termios info;
	tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
	info.c_lflag &= ~ICANON;      /* disable canonical mode */
	info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
	info.c_cc[VTIME] = 0;         /* no timeout */
	tcsetattr(0, TCSANOW, &info); /* set immediately */
	char command;

	while(1){
		command = getchar();

		switch (command)
		{
		    case '4':
		    	system("xdotool key XF86AudioPrev");
		    	break;
			case '6':
		    	system("xdotool key XF86AudioNext");
		     	break;
			case '2':
		    	system("xdotool key XF86AudioLowerVolume");
		     	break;
			case '8':
		    	system("xdotool key XF86AudioRaiseVolume");
		     	break;
			case '5':
		    	system("xdotool key XF86AudioPlay");
		     	break;
		     case '7':
		    	system("xdotool key XF86AudioMute");
		     	break;
			case '0':
				return 0;
		     	break;
		}

	}	


	return 0;
}