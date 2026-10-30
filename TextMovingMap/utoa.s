;
; utoa
;
_utoa
	ldy #0
	lda (sp),y
	sta op2
	iny
	lda (sp),y
	sta op2+1

	jsr utoa
	rts

bufconv1
	.byt 0,0,0,0,0,0,0,0,0,0,0,0


utoa
	ldy #0
	sty bufconv1
utoaloop
	jsr uudiv10
	pha
	iny
	lda op2
	ora op2+1
	bne utoaloop
	
	ldx #0
	lda bufconv1
	beq poploop1
	inx
poploop1
	pla
	clc
	adc #$30
	sta bufconv1,x
	inx
	dey
	bne poploop1
	lda #0
	sta bufconv1,x
	ldx #<bufconv1
	lda #>bufconv1
	rts
			
;
; udiv10 op2= op2 / 10 and A= tmp2 % 10
;
uudiv10
	lda #0
	ldx #16
	clc
uudiv10lp
	rol op2
	rol op2+1
	rol 
	cmp #10
	bcc contdiv1
	sbc #10
contdiv1
	dex
	bne uudiv10lp
	rol op2
	rol op2+1
    rts
        
