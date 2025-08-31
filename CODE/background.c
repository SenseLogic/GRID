
#define BackgroundLineIndex    ( *( volatile UINT_8 * )0x02FB )
#define BackgroundUpperColor    ( *( volatile UINT_8 * )0x02FC )
#define BackgroundLowerColor    ( *( volatile UINT_8 * )0x02FD )

// -- FUNCTIONS

void __fastcall__ ChangeBackgroundColor(
    void
    )
{
    __asm__ (
        "sei\n"
        "pha\n"
        "txa\n"
        "pha\n"
        "tya\n"
        "pha\n"

        "lda $D019\n"
        "ora #$10\n"
        "sta $D019\n"

        "lda $D011\n"
        "and #$80\n"
        "bne already_done\n"

        "check_raster:\n"
        "lda $D012\n"
        "cmp $02FB\n"
        "bcs set_lower_color\n"

        "set_upper_color:\n"
        "lda $02FC\n"
        "sta $D020\n"    // Set upper frame color
        "sta $D021\n"    // Set upper background color

        "lda $DC00\n"    // Read joystick 2 state
        "eor #$FF\n"
        "ora $02FF\n"
        "sta $02FF\n"

        "lda $DC01\n"    // Read joystick 1 state
        "eor #$FF\n"
        "ora $02FE\n"
        "sta $02FE\n"

        "lda $D011\n"
        "and #$7F\n"
        "sta $D011\n"

        "lda $02FB\n"
        "sta $D012\n"
        "bne done\n"

        "set_lower_color:\n"
        "lda $02FD\n"
        "sta $D020\n"    // Set lower frame color
        "sta $D021\n"    // Set lower background color

        "lda $D011\n"
        "and #$7F\n"
        "sta $D011\n"

        "lda #0\n"
        "sta $D012\n"

        "done:\n"
        "lda $D019\n"
        "ora #$01\n"
        "sta $D019\n"

        "already_done:\n"
        "pla\n"
        "tay\n"
        "pla\n"
        "tax\n"
        "pla\n"
        "cli\n"
        "jmp $EA31\n"
        );
}

// ~~

void InitializeBackground(
    void
    )
{
    BackgroundLineIndex = 176;
    BackgroundUpperColor = COLOR_Black;
    BackgroundLowerColor = COLOR_Blue;

    *(volatile UINT_8 *)0xD020 = COLOR_Blue;
    *(volatile UINT_8 *)0xD021 = COLOR_Blue;

    __asm__ ( "sei" );
    *(volatile UINT_8 *)0x0314 = (UINT_16)ChangeBackgroundColor;
    *(volatile UINT_8 *)0x0315 = (UINT_16)ChangeBackgroundColor >> 8;

    *(volatile UINT_8 *)0xDC0D = 0x7F;
    *(volatile UINT_8 *)0xD01A |= 0x01;

    *(volatile UINT_8 *)0xD011 &= 0x7F;
    *(volatile UINT_8 *)0xD012 = 0x00;

    *(volatile UINT_8 *)0xD019 |= 0x01;
    __asm__ ( "cli" );
}
