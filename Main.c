// Dungeoneer developed by Daniel Varholdt
// 5/30/2021
// Milestone 2: Application Release 1
// For ITS 310
//
// Basic text rpg that allows for users to designate character and dungeon name
// Users are able to choose from specific dialogue options to influence the story
// 
// Good luck!

#include <stdio.h> // Basic library
#include <stdlib.h> // For NULL, EXIT_FAILURE, EXIT_SUCCESS
#include "Name.h" // For choosing player name
#include "Dungeon.h" // For choosing dungeon name
#include <conio.h> // For getch() & clrscr() 
#include <ctype.h> // For testing & mapping characters 
#include <time.h> // To get current time
#include <string.h> // For strlen

// Global variables, initializing all choices to 0 prior
int choice1 = 0;
int choice2 = 0;
int choice3 = 0;
int choice4 = 0;
int choiceexit = 0;

void asciigear(void)
{
    puts(
        "                                                                                \n"
        "                                                                                \n"
        "                         ..                                                     \n"
        "                        ....                                                    \n"
        "                        ....                                                    \n"
        "                        ....              .******(%%//%#/******                 \n"
        "                        ....           ****%###%#%#(..#####%%%*****             \n"
        "                        ....           *%%%%%%%%%%%( .##%%%%%%%%%**             \n"
        "                        ....           *%#%%%%%%%%%(..#%%%%#%%%%%**             \n"
        "                        ....           ,%#%%%%#%%%%(..%%#%###%%%%**             \n"
        "                        ....           ,%%%%%%%%%%##  #%#%###%%%%**             \n"
        "                        ....           ,%%%###%%#%,,,,*,##%##%%%%,,             \n"
        "                        ....           ,(.   . . ,,,,,,#, .    ..,,             \n"
        "                        ....           ,,%%%%%%%%##,,,,###%%%%%%%,              \n"
        "                        ....            ,#%%%##%#%%%..#%%###%%##,,              \n"
        "                     %%%%%%%%%#          ,,###%####%..##%#%%%%%**               \n"
        "                   ,#%* %%%%..%%.         .,,%#%%%%%..%%%%%%%**                 \n"
        "                        (%%#                 ***%%%%..%%%,**.                   \n"
        "                        #%%%                      ******                        \n"
        "                         %%#                                                    \n"
        "                        #%%%.                                                   \n"
        "                                                                                \n"
        "                                                                                \n"
    );
};
void asciimonster(void)
{
    puts(
        "                                        \n"
        "                                        \n"
        "                  ****%#,               \n"
        "               /,,*//#////*,,           \n"
        "              /,,*,,.*/////*,.          \n"
        "              ,.*%*//,..,&///,          \n"
        "              #%..,..#/. /(/**,         \n"
        "              %.,.,/,,,*#(//.(          \n"
        "               #.,*,,/#///. .           \n"
        "                   / ....,(**,          \n"
        "                  /,.(*,,.***%***       \n"
        "                 .,,,,,,....*****       \n"
        "               .,,,,,,,,,..*********    \n"
        "               ..,,,,,,,,,   ,******,   \n"
        "               ..,,,,,,,..,.  ..  ,..   \n"
        "              .  . ,,,/***(*,,    /*/(#,\n"
        "               ..,,,,,*/(**,,      /....\n"
        "             . ...,,,*//**#*..      /%%/\n"
        "           .... .,,,,,,*/***,        /%%\n"
    );
};
void asciitreasure(void)
{
    puts(
        "                            _.--.              \n"
        "                        _.-'_:-'||             \n"
        "                    _.-'_.-::::'||             \n"
        "               _.-:'_.-::::::'  ||             \n"
        "             .'`-.-:::::::'     ||             \n"
        "            /.'`;|:::::::'      ||_            \n"
        "           ||   ||::::::'     _.;._'-._        \n"
        "           ||   ||:::::'  _.-!oo @.!-._'-.     \n"
        "           |'.  ||:::::.-!()oo @!()@.-'_.|     \n"
        "            '.'-;|:.-'.&$@.& ()$%-'o.'-'||     \n"
        "              `>'-.!@%()@'@_%-'_.-o _.|'||     \n"
        "               ||-._'-.@.-'_.-' _.-o  |'||     \n"
        "               ||=[ '-._.--''.-'    o |'||     \n"
        "               || '-.]=|| |'|      o  |'||     \n"
        "               ||      || |'|        _| '|     \n"
        "               ||      || |'|    _.-'_.-'      \n"
        "               |'-._   || |'|_.-'_.-'          \n"
        "                '-._'-.|| |' `_.-'             \n"
        "                    '-.||_|.-'                 \n"
    );
};
void asciiskull(void)
{
    puts(
        "           ______           \n"
        "        .-"      "-.        \n"
        "       [            ]       \n"
        "      |              |      \n"
        "      |,  .-.  .-.  ,|      \n"
        "      | )(__|  |__)( |      \n"
        "      |/     /\\     \\|      \n"
        "      (_     ^^     _)      \n"
        "       |__|IIIIII|__|       \n"
        "        | \\IIIIII/ |        \n"
        "        |          |        \n"
        "         `--------`         \n"
        "                            \n"
    );
};
void ascii8ball(void)
{
    puts(
        "                                  \n"
        "            _.a$$$$$a._           \n"
        "          ,$$$$$$$$$$$$$.         \n"
        "        ,$$$$$$$$$$$$$$$$$.       \n"
        "       d$$$$$$$$$$$$$$$$$$$b      \n"
        "      d$$$$$$$$~~'!~$$$$$$$$b     \n"
        "     ($$$$$$$p   _   q$$$$$$$)    \n"
        "     $$$$$$$$   (_)   $$$$$$$$    \n"
        "     $$$$$$$$   (_)   $$$$$$$$    \n"
        "     ($$$$$$$b       d$$$$$$$)    \n"
        "      q$$$$$$$$a._.a$$$$$$$$p     \n"
        "       q$$$$$$$$$$$$$$$$$$$p      \n"
        "        `$$$$$$$$$$$$$$$$$'       \n"
        "          `$$$$$$$$$$$$$'         \n"
        "            `~$$$$$$$~'           \n"
        "                                  \n"
    );
};
void asciiexplosion(void)
{
    puts(
        "                                        %%              %/                      \n"
        "                                %/#/    **    %(#                               \n"
        "                           #    (/./%. .(#  %(*/%                               \n"
        "                   %#       %/% *(,../%#,/%(*../%   %%        /.                \n"
        "                     %///#%(.%/./#*. ..* .*.  ./%(*(* /%%(/(%                   \n"
        "                       #(/....//. ..   .     .,. *//..../%*                     \n"
        "                   #%#%%%%#/.                       ./(%                        \n"
        "                       ##/,.                      .*****//(%.                   \n"
        "               *%%##///*....                       ....///(#%%,                 \n"
        "                  .(%##///*...                      ....*///(#%%*.              \n"
        "                    ##/*,,,,,..                     ./#/                        \n"
        "                        .%/..                 .     ./(///%/                    \n"
        "                      #(/..,//, .,.     ..     .(//,.../##                      \n"
        "                    %/(#%( %/,/%%/.  .. //.  ./,.#   (%#//(%                    \n"
        "                 (        %%.   %/../#*(% %/../#%/%         (%                  \n"
        "                                #//#*%/%   *#//#. .%                            \n"
        "                               *(%/   %      #(#*                               \n"
    );
};
void asciicongrats(void)
{
    puts(
        "                                    _           \n"
        "                                   | |          \n"
        "     ___ ___  _ __   __ _ _ __ __ _| |_ ___     \n"
        "    / __/ _ \\| '_ \\ / _` | '__/ _` | __/ __|    \n"
        "   | (_| (_) | | | | (_| | | | (_| | |_\\__ \\    \n"
        "    \\___\\___/|_| |_|\\__, |_|  \\__,_|\\__|___/    \n"
        "                     __/ |                      \n"
        "                    |___/                       \n"
    );
};
void choice1loop(void)
{
    while(1)
    {
        char buffer[1024];
        int _getche();

        // main choice area, 1 to continue onward, 2 to fail and retry choice, anything else to error.
        printf("\nYou have a choice now. Will you... 1. Go out and attempt to save the town?. 2. Go back to sleep...\n");
        scanf_s("%i", &choice1);
        system("cls");

        // Used to stop infinite loop when char input into scanf_s
        const char* str = fgets(buffer, sizeof(buffer), stdin);
        if (str == NULL) { /* error - handle it */ }

        if (choice1 == 1) // Choice that allows user to break from this loop to continue story
        {
            break; // breaks out of loop
        }

        else if (choice1 == 2) // Choice that forces user to restart from beginning of this loop
        {
            printf("\nYou go back to bed. The monsters overrun the city and you have died...\n");
            printf("\nYou have failed. Hit any key to return to last choice.\n");
            _getche();
            system("cls");
        }

        else // Choice that forces user to restart from beginning of this loop
        {
            printf("\nNot a valid choice, try again\n");
            _getche();
            system("cls");
        }
    }
}
void choice2loop(void)
{
    while(1)
    {
        char buffer[1024];
        int _getche();

        //choice area, 1 to continue onward, 2 to fail and retry choice, anything else to error.
        printf("\nQuickly thinking. You: 1. Try to attack the Goblin! 2. Run away from the Goblin... 3. Cower in fear... \n");
        scanf_s("%d", &choice2);
        system("cls");

        // Used to stop infinite loop when char input into scanf_s
        const char* str = fgets(buffer, sizeof(buffer), stdin);
        if (str == NULL) { /* error - handle it */ }

        if (choice2 == 1) // Choice that allows user to break from this loop to continue story
        {
            printf("\nYou draw your trusty sword and shield and get into defensive position\n");
            printf("\nThe Goblin attempts to get the first attack and swings with all of its might down upon your shield!\n");
            printf("\nYou block the powerful attack and counter with one of your own. You have trained your whole life for moments like these.\n");
            printf("\nDeflecting the attack, you knock the Goblins sword clear of its hand. Seeing the opportunity, you strike!\n");
            printf("\nAnd just like every other monster you have ever slain, you thrust your sword deep into the heart of the monster...\n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            //ASCII art using puts()
            asciitreasure();

            printf("\nYou have defeated the Goblin!!! ***Victory fanfare***\n");
            printf("\nYou have earned the Goblins treasure that it has left behind!!!\n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nUpon further inspection, you notice that the coins in the chest are all soft...\n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nYou take a bite into the coin to test it, and your teeth sink into the coin.\n");
            printf("\nFor some reason it tastes alot like chocolate......\n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");
            break;
        }

        else if (choice2 == 2) // Choice that allows user to break from this loop to continue story
        {
            printf("\nYou try to run away from the Goblin but he throws a spear right into your back!\n");
            printf("\nYou have failed. Hit any key to return to last choice.\n");
            _getche();
            system("cls");
        }

        else if (choice2 == 3) // Choice that forces user to restart from beginning of this loop
        {
            printf("\nYou cower in fear as the Goblin is free to strike you with his sword and you have died...\n");
            printf("\nYou have failed. Hit any key to return to last choice.\n");
            _getche();
            system("cls");
        } 
        else  // Choice that forces user to restart from beginning of this loop
        {
            printf("\nNot a valid choice, try again\n");
            _getche();
            system("cls");
        }
    }
}
void choice3loop(void)
{

    union Money {
        int coins;
        int jobs;
        int intelligence;
    } money;

    money.coins = 0; // for use in money union 


    while(1)
    {
        char buffer[1024];
        int _getche();

        //ASCII art using puts()
        asciiskull();

        printf("\nYou see a skull shaped switch that may belong to this suspicious gate.\n\nIt looks like you can insert a coin into the mouth.\n\nDo you 1. Try to Insert coin? 2. Ignore the switch?\n");
        scanf_s("%d", &choice3);
        system("cls");

        // Used to stop infinite loop when char input into scanf_s
        const char* str = fgets(buffer, sizeof(buffer), stdin);
        if (str == NULL) { /* error - handle it */ }

        if (choice3 == 1) // Choice that forces user to restart from beginning of this loop, use of union
        {
            printf("\nYou approach the switch with intent to insert a coin, but the skull speaks to you. \n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nSkull: I can see inside your mind. You will not be able to open this door because I know that you have no money! \n");
            printf("\nSkull: I will now tell you about yourself! \n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nSkull: The amount of money that you have is %d! \n", money.coins);
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nSkull: This is because the amount of jobs that you have had in your life amounts to %d! \n", money.jobs);
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nSkull: And this is because the total IQ that you have in that skull of yours is %d! \n", money.intelligence);
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");

            printf("\nNow give me real coins to open this door, or SCRAM!!! \n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");
        }

        else if (choice3 == 2) // Choice that allows user to break from this loop to continue story
        {
            printf("\nYou decide to ignore the suspicious switch and carry on through the open doorway \n");
            printf("\nPress any key to Continue...\n");
            _getche();
            system("cls");
            break;
        }

        else // Choice that forces user to restart from beginning of this loop
        {
            printf("\nNot a valid choice, try again\n");
            _getche();
            system("cls");
        }
    }
}
void choice4loop(void)
{
    while(1)
    {

        char buffer[1024];
        int _getch();

        printf("\nThis is the final choice!! Do you... 1. Attack the faceless being head on? 2. Hide and try to sneak attack the being? 3. Sneakily search the room for an advantage.\n");
        scanf_s("%d", &choice4);
        system("cls");

        // Used to stop infinite loop when char input into scanf_s
        const char* str = fgets(buffer, sizeof(buffer), stdin);
        if (str == NULL) { /* error - handle it */ }

        if (choice4 == 1) // Choice that forces user to restart from beginning of this loop
        {
            printf("\nYou scream at the top of your lungs and catch the beings attention as you rush haphazardly at full speed.\n");
            printf("\nThe being does not react as you close the distance.\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\n10 meters...\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\n5 meters...\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\nAs you are almost within arms length of the faceless figure, its arm outstretches in your direction.\n");
            printf("\nA whirlwind of darkness surrounds you as you go blind.\n");
            printf("\nAll feeling in your body has disappeared and you can no longer tell where you are...\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\nThe being has destroyed your soul. You have failed. Hit any key to return to last choice.\n");
            _getch();
            system("cls");

        }

        else if (choice4 == 2) // Choice that allows user to break from this loop to continue story
        {
            printf("\nYou decide to try and be sneaky as you hug the edges of the walls and make your way closer to the being.\n");
            printf("\nDirectly behind the throne now, with now way of the being seeing you, you attempt to close the distance.\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\n10 Meters...\n");
            printf("\n5 Meters...\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\nTouching the back of the throne now, you unsheathe your sword very slowly and silently. The being still has not noticed you.\n");
            printf("\nVery carefully, you point your sword towards the back of the throne.\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\nThrusting with the might of the gods, you jam your sword into the back of the throne, hoping that it penetrates.\n");
            printf("\nRelief washes over you as the sword slides cleanly through the back lining of the throne into the back of the faceless creature.\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            break;
        }

        else if (choice4 == 3) // Choice that allows user to break from this loop to continue story
        {
            printf("\nLooking around the environment, a bright object catches your eye.\n");
            printf("\nCarefully, you make your way towards the bright ball of light.\n");
            printf("\nCan it be???\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            //ASCII art using puts()
            ascii8ball();

            printf("\nThe magical 8 ball of destiny!!!\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");

            printf("\nAs if the 8 ball of destiny was speaking to you...\n");
            printf("\nIt tells you to throw it at the faceless being sittng in the throne.\n");
            printf("\nDoing exactly that, you maintain your distance as you lob the 8 ball of destiny towards the throne.\n");
            printf("\nPress any key to Continue...\n");
            _getch();
            system("cls");
            break;
        }

        else // Choice that forces user to restart from beginning of this loop
        {
            printf("\nNot a valid choice, try again\n");
            _getch();
            system("cls");
        }
    }
}
void readfile(void)
{
    int _getche(); // return no error call for _getch
    FILE* fp = NULL;
    errno_t err;
    char buff[255];

    // open file, if file contents are null, throw error
    err = fopen_s(&fp, "dlc.txt", "r");
    if (fp == NULL)
    {
        printf("\nError while opening file\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");
        fclose(fp);
    }

    fgets(buff, 255, (FILE*)fp); // Using fgets to get the string from the file
    printf("%s\n", buff); // Print string from the filer to the buffer size
    fclose(fp); // Close the file

    printf("\nPress any key to redo choice..\n");
    _getche();
    system("cls");
}
void writefile(void)
{
    int _getche();
    errno_t err;
    FILE* fp;

    // Open file to write, if file does not exist, it will be created
    err = fopen_s(&fp, "dlc.txt", "w");
    fprintf(fp, "Hello! You have found the secret hidden file at the end of my project!!! Well I guess it wasnt that hidden... Anyways, congradulations for reaching this point!! \n");

    if (fp == NULL) // If file cannot be opened, throw null error
    {
        printf("\nError while opening file\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");
        fclose(fp); //close the file
    }

    fclose(fp); //close the file
}
int main()
{
    char fn[65]; // Character array to hold a users first name 
    char dn[65]; // Character array to hold dungeon name
    char buffer[1024]; // buffer for char to stop inf loop 
    int _getche(); // return no error call for _getch
    int extradata = 0; // Initializing for error checking in Player / dungeon name input

    // Usage of struct to display time at beginning of story
    time_t s; 
    struct tm *current_time; // tm struct for time display
    s = time(NULL); 
    current_time = localtime(&s); 

    // Main loop of the story, once something happens that causes the story to end, restarts from this point 
    for (;;)
    {
        // Prompt from stdin for a users name
        printf(PROMPT_MSG);

        // If fgets has no more to read or if there is an error
        fn[sizeof fn - 1] = 'x';
        if (fgets(fn, 65, stdin) == NULL)
        {
            return 0; 
        }

        // If extra characters or int input, get rid of extra input after buffer size reached
        if (fn[sizeof fn - 1] == '\0' && fn[sizeof fn - 2] != '\n')
        {
            int exch;
            while ((exch = fgetc(stdin)) != '\n' && exch != EOF)
            {
                extradata = 1;
                break;
            }
        }

        // Remove trailing newline after fgets for player name
        fn[strcspn(fn, "\n")] = 0;

        // Prompt from stdin for the dungeon name and clear screen after both user input
        printf(PROMPT_MSGD);

        // No more to read or IO error
        dn[sizeof dn - 1] = 'x';
        if (fgets(dn, 65, stdin) == NULL) 
        {
            break;
        }

        // If extra characters or int input, get rid of extra input after buffer size reached
        if (dn[sizeof dn - 1] == '\0' && dn[sizeof dn - 2] != '\n')
        {
            int exch;
            while ((exch = fgetc(stdin)) != '\n' && exch != EOF)
            {
                extradata = 1;
                break;
            }
        }

        // Remove trailing newline after fgets for dungeon name
        dn[strcspn(dn, "\n")] = 0;

        // Waits for user input to continue and then clears the screen
        printf("\nPress any key to Continue...\n");
        _getche(); // user input
        system("cls"); // clear screen

        // Further dialogue pushing the story forward, usage of struct to display time.
        printf("\nYou rudely awaken at the sound of someone yelling for your name.\n");
        printf("\nYou look at your clock, the time is %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
        printf("\nSomeone is standing above you and they reach for you.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nThey begin shaking you harshly in an attempt to wake you up and get your attention. It is the town eldar known as Zylo!\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        // Print the users name using stdout & Basic dialogue with the dungeon name. Wait for user input to continue.
        printf("\nZylo: Wake up!!! the town alarm is going off and we need your help %s\n", fn);
        printf("\nZylo: The dungeon just outside the town is being overrun by monsters and they are starting to come into the city now!\n");
        printf("\nZylo: We need your help to stop them... Please grab your weapon and get to the front of the dungeon %s\n", dn);
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        //ASCII art using puts()
        asciigear();

        printf("\nYou gather the needed equipment... Your trusty hildebrand sword and custom fitted ironwood shield.\n");
        printf("\nAs you exit your house, you hear the deafening screams of the townsfolk and the blaring alarm.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        // Loop to require user input to pick between choices presented. Other input not allowed.
        choice1loop();

        //further dialogue pushing the story forward
        printf("\nyou continue onward...\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nYou quickly sprint through the chaotic scene of fire and destruction that lay about to the front of the dungeon %s\n", dn);
        printf("\nYou see hordes of monsters pouring out of the dungeon, looking for an alternative entrance, you notice a path around the back of the cave.\n");
        printf("\nSuccess! A small hole in the side of the cave leading even deeper in! You wiggle your way into the cracks and have successfully entered the dungeon without getting noticed by the monsters outside.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nOnce you are inside the dungeon, you notice a pungent smell. It is very hard to see inside the dimly lit dungeon, but you make out the faint image of what looks like a person.\n");
        printf("\nAs you approach it slowly, you quickly realize that they are not what they seem... \n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nThe creature quickly flips around at the slightest sound of crushing a pebble with your boots. You quickly hide in cover.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        //ASCII art using puts()
        asciimonster();

        printf("\nThe faceless creature peers down the dimly lit cave, looking for what may have startled it.\n");
        printf("\nYou get shivers up your spine from the sheer site of this unknown being, and you begin to question your motives.\n");
        printf("\n'You are the one and only hero! You have slayed countless beasts and defended the city before...' you tell yourself.\n");
        printf("\nBut this creature is like no other that you have ever seen and you begin feel the pit of your stomach sinking further.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nFeeling quesy, you try to get some quick rest. You quickly peek back out to see the whereabouts of the creature, but it is gone...\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nThe sound of footsteps quickly approach from behind you. Before you can even turn around you hear what sounds to be a garbled 'INTRUDER!!!' \n");
        printf("\nYou stammer to your feet at the sight of a large goblin...\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        // Loop to require user input to pick between choices presented. Other input not allowed.
        choice2loop();

        //further dialogue pushing the story forward
        printf("\nYou quickly make your way down the dungeon in pursuit of the faceless creature that you saw before you.\n");
        printf("\nArriving in front of a suspicious looking doorway along the walls of the dungeon, you stop and investigate\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        // Loop to require user input to pick between choices presented. Other input not allowed.
        choice3loop();

        //further dialogue pushing the story forward
        printf("\nYou continue onward in the dungeon. After countless hours of navigating the dungeon, you finally arrive at a vastly open space within the dungeon.\n");
        printf("\nPiles of gold and riches sprawled about, and clouds covering the ceiling. You see the faceless figure sitting upon a dark, shadowey throne.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        // Loop to require user input to pick between choices presented. Other input not allowed.
        choice4loop();

        //ASCII art using puts()
        asciiexplosion();

        // Final dialogue section
        printf("\nThe throne bursts into a shadowey ball of flame as it envelopes the entire room.\n");
        printf("\nYou are knocked unconscious from the sheer blast.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\n%s...\n", fn);
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\n%s please...\n", fn);
        printf("\nplease wake up...\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\n...............\n");
        printf("\n...............\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nIt has been countless nights, but finally you are awake.\n");
        printf("\nZylo: Oh thank the heavens! You are awake %s!!! We were so worried that you would not awaken after your battle...\n", fn);
        printf("\nZylo: Here, let me help you up.\n");
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nZylo helps you up, and you both walk outside.\n");
        printf("\nYou see a large statue in progress which oddly enough seems to resemble yourself.\n");
        printf("\nZylo: It is you %s! We are building a statue in honor of you saving the town!\n", fn);
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        printf("\nYou are our hero %s\n", fn);
        printf("\nPress any key to Continue...\n");
        _getche();
        system("cls");

        //ASCII art using puts()
        asciicongrats();

        // Loop to require user input to pick between choices presented. Other input not allowed.
        for (;;)
        {
            printf("\nEnd of the road!\n");
            printf("\nType 1 to restart. 2 to quit. 3 to load extra content\n");
            scanf_s("%d", &choiceexit);
            system("cls");

            // Used to stop infinite loop when char input into scanf_s
            char* str = fgets(buffer, sizeof(buffer), stdin);
            if (str == NULL) { /* error - handle it */ }

            // Restarts full loop and sends player back to beginning of program
            if (choiceexit == 1)
            {
                break;
            }

            // Exits program
            else if (choiceexit == 2)
            {
                return 0;
            }

            // Choice to execute file I/O for extra content at end of program
            else if (choiceexit == 3)
            {
                writefile();
                readfile();
            }

            else // Choice that forces user to restart from beginning of this loop
            {
                printf("\nNot a valid choice, try again\n");
                _getche();
                system("cls");
            }
        }
    }
    return 0;
}