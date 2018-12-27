

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