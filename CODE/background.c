// -- CONSTANTS

#define BackgroundLineIndex    ( *( volatile char * )0x02FB )
#define BackgroundUpperColor   ( *( volatile char * )0x02FC )
#define BackgroundLowerColor   ( *( volatile char * )0x02FD )

// -- FUNCTIONS

void ChangeBackgroundColor(
    )
{
    __asm
    {
        sei
        pha
        txa
        pha
        tya
        pha
        lda $D019
        ora #$10
        sta $D019
        lda $D011
        and #$80
        bne already_done
    check_raster:
        lda $D012
        cmp $02FB
        bcs set_lower_color
    set_upper_color:
        lda $02FC
        sta $D020    // Set upper frame color
        sta $D021    // Set upper background color
        lda $DC00    // Read joystick 2 state
        eor #$FF
        ora $02FF
        sta $02FF
        lda $DC01    // Read joystick 1 state
        eor #$FF
        ora $02FE
        sta $02FE
        lda $D011
        and #$7F
        sta $D011
        lda $02FB
        sta $D012
        bne done
    set_lower_color:
        lda $02FD
        sta $D020    // Set lower frame color
        sta $D021    // Set lower background color
        lda $D011
        and #$7F
        sta $D011
        lda #0
        sta $D012
    done:
        lda $D019
        ora #$01
        sta $D019
    already_done:
        pla
        tay
        pla
        tax
        pla
        cli
        jmp $EA31
    }
}

// ~~

void InitializeBackground(
    void
    )
{
    BackgroundLineIndex = 176;
    BackgroundUpperColor = COLOR_Black;
    BackgroundLowerColor = COLOR_Blue;

    *(volatile char *)0xD020 = COLOR_Blue;
    *(volatile char *)0xD021 = COLOR_Blue;

    __asm { sei }

    *(volatile char *)0x0314 = (char)((unsigned)ChangeBackgroundColor);
    *(volatile char *)0x0315 = (char)((unsigned)ChangeBackgroundColor >> 8);
    *(volatile char *)0xDC0D = 0x7F;
    *(volatile char *)0xD01A |= 0x01;
    *(volatile char *)0xD011 &= 0x7F;
    *(volatile char *)0xD012 = 0x00;
    *(volatile char *)0xD019 |= 0x01;

    __asm { cli }
}
