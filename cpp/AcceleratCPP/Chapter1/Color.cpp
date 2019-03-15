#include <stdio.h>  
#include <Windows.h>  
  
int main(void)  
{  
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  
    WORD wOldColorAttrs;  
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;  
    // Save the current color  
    GetConsoleScreenBufferInfo(h, &csbiInfo);  
    wOldColorAttrs = csbiInfo.wAttributes;  
  
    // Set the new color  
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);  
    printf("This is a test\n");  
  
    // Restore the original color  
    SetConsoleTextAttribute(h, wOldColorAttrs);  
    printf("This is a test\n");  
    char* s;
    scanf("%s",s);
    return 1;
}  