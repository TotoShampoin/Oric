

_testmem
.(
	ldy #0
	lda (sp),y
	sta tmp0
	iny
	lda (sp),y
	sta tmp0+1
	
	iny
	lda (sp),y
	tay
	dey
boucle1
	lda (tmp0),y
	beq zerotrouve
	dey
	bne boucle1
	lda #0
	ldx #0
	rts
	
zerotrouve
	lda #1
	ldx #1
	rts

.)

color
.dsb 1

nblignes
.dsb 1

saverti
.dsb 3

ADDRSCRN
.dsb 2

_animate
.(
	pha
	txa
	pha
	php

	lda ADDRSCRN
	sta locaddr+1
	lda ADDRSCRN+1
	sta locaddr+2
	
	ldx nblignes
	dec color
	lda color
	bne suite
	lda #7
	sta color

suite
	lda color
locaddr
	sta $1234
	lda #40
	clc
	adc locaddr+1
	sta locaddr+1
	lda locaddr+2
	adc #0
	sta locaddr+2
	dex
	bne suite
	
	plp
	pla
	tax
	pla
	rti
.)

_setanimate
.(
	
	ldy #0
	lda (sp),y
	sta ADDRSCRN
	iny
	lda (sp),y
	sta ADDRSCRN+1
	
	iny
	lda (sp),y
	sta nblignes
	
	sei
	lda #7
	sta color
	lda $24A
	sta saverti
	lda $24B
	sta saverti+1
	lda $24C
	sta saverti+2
	lda #$4C
	sta $24A
	lda #<_animate
	sta $24B
	lda #>_animate
	sta $24C
	cli
	rts
.)

_unsetanimate
.(
	sei
	lda #7
	sta color
	lda saverti
	sta $24A
	lda saverti+1
	sta $24B
	lda saverti+2
	sta $24C
	cli
	rts
.)
