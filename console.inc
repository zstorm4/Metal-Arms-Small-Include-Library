enum
    {
    black,      /* colours as per the ANSI Escape sequences, ISO 6429 */
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    }

native getchar(echo=true);
native getstring(string[], maxlength=sizeof string, bool:pack=false);
native getvalue(base=10, end=0x0d, ...);    /* 0x0d == '\r' */
native print();
native printf();

native clrscr();        /* also resets the cursor to (1,1) */
native clreol();
native gotoxy(x=1, y=1);
native setattr(foreground=-1, background=-1, highlight=-1);
