_CG_DEFCHAR
.(
	lda #<_CG_DATA
	sta tmp0
	lda #>_CG_DATA
	sta tmp0+1
	lda #$D0
	sta tmp1
	lda #$B6
	sta tmp1+1
		
	ldy #0
boucle2
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle2
	
	rts
.)

_CG_DATA

.byt 0,0,0,0,0,0,0,0
.byt 0,0,0,0,0,0,0,0
.byt 0,0,0,0,0,0,0,0
.byt 0,0,0,0,0,0,0,0

.byt 0,15,31,31,31,31,31,31

.byt 0,60,62,62,62,62,62,62

.byt 31,31,31,31,31,31,15,0

.byt 62,62,62,62,62,62,60,0

.byt 0,1,3,3,7,15,15,31

.byt 0,32,48,48,56,60,60,62

.byt 31,15,15,7,3,3,1,0

.byt 62,60,60,56,48,48,32,0

.byt 0,1,3,15,31,31,31,31

.byt 0,32,48,60,62,62,62,62

.byt 31,31,31,31,15,3,1,0

.byt 62,62,62,62,60,48,32,0

.byt 0,15,31,31,31,31,15,15

.byt 0,60,62,62,62,62,60,60

.byt 15,7,7,3,3,1,1,0

.byt 60,56,56,48,48,32,32,0

.byt 0,1,1,3,3,3,7,7

.byt 0,32,32,48,48,48,56,56

.byt 15,15,15,31,31,31,0,0

.byt 60,60,60,62,62,62,32,0

.byt 0,7,15,31,63,63,63,63

.byt 0,48,56,60,62,62,62,62

.byt 63,63,63,63,31,15,7,0

.byt 62,62,62,62,60,56,48,0

.byt 0,1,3,15,31,31,31,31

.byt 0,32,48,60,62,62,62,62

.byt 31,31,31,31,15,3,1,0

.byt 62,62,62,62,60,48,32,0
	