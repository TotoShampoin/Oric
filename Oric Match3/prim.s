


ranPGTMP .byt $00
_rand01
.(
	ldx #$ff
	jsr $E355
	lda $D1
	and #$01
	tax
	lda #$00
	rts
.)

_rand1248
.(
	ldx #$ff
	jsr $E355
	lda $D1
	and #$0F
	tax
	lda #$00
	rts
.)

_rand124
.(
	ldx #$ff
	jsr $E355
	lda $D1
	and #$07
	tax
	lda #$00
	rts
.)