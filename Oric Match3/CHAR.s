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
	

	lda #<_CG_DAT2
	sta tmp0
	lda #>_CG_DAT2
	sta tmp0+1
	lda #$08
	sta tmp1
	lda #$B5
	sta tmp1+1
		
	ldy #(15*8)
boucle3
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle3
	
	lda #<_CG_DAT4
	sta tmp0
	lda #>_CG_DAT4
	sta tmp0+1
	lda #$E0
	sta tmp1
	lda #$B5
	sta tmp1+1
		
	ldy #(3*8)
boucle4
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle4
	rts
.)

_CG_DATA
;;; rien
.byt 0,0,0,0,0,0,0,0
.byt 0,0,0,0,0,0,0,0
.byt 0,0,0,0,0,0,0,0
.byt 0,0,0,0,0,0,0,0
;;; 1
.byt 0,15,31,31,31,31,31,31
.byt 0,60,62,62,62,62,62,62
.byt 31,31,31,31,31,31,15,0
.byt 62,62,62,62,62,62,60,0
;;; 2
.byt 0,1,3,3,7,15,15,31
.byt 0,32,48,48,56,60,60,62
.byt 31,15,15,7,3,3,1,0
.byt 62,60,60,56,48,48,32,0
;;; 3
.byt 0,1,3,15,31,31,31,31
.byt 0,32,48,60,62,62,62,62
.byt 31,31,31,31,15,3,1,0
.byt 62,62,62,62,60,48,32,0
;;; 4
.byt 0,15,31,31,31,31,15,15
.byt 0,60,62,62,62,62,60,60
.byt 15,7,7,3,3,1,1,0
.byt 60,56,56,48,48,32,32,0
;;; 5
.byt 0,1,1,3,3,3,7,7
.byt 0,32,32,48,48,48,56,56
.byt 7,15,15,15,31,31,31,0
.byt 56,60,60,60,62,62,62,0
;;; 6
.byt 0,3,7,15,31,31,31,31
.byt 0,48,56,60,62,62,62,62
.byt 31,31,31,31,15,7,3,0
.byt 62,62,62,62,60,56,48,0
;;; 7
.byt 0,1,7,15,15,15,31,31
.byt 0,32,56,60,60,60,62,62
.byt 31,31,15,15,15,7,1,0
.byt 62,62,60,60,60,56,32,0
;;;
_CG_DAT2  ;;; Tour !"#$%& 
.byt 0,0,0,15,15,12,12,12	
.byt 0,0,0,63,63,0,0,0	
.byt 0,0,0,60,60,12,12,12
.byt 12,12,12,12,12,12,12,12	
.byt 12,12,12,15,15,0,0,0	
.byt 12,12,12,60,60,0,0,0

;;;curseur '()
.byt 12,12,12,63,63,12,12,12	
.byt 12,12,12,60,60,12,12,12
.byt 12,12,12,63,63,0,0,0	

;;; The END *+,-./

.byt 0,1,2,5,11,11,23,23	
.byt 30,33,30,63,63,63,63,63	
.byt 0,32,16,40,52,52,58,58
;;;
.byt 47,40,43,40,43,40,47,47	
.byt 63,45,37,41,45,45,63,63	
.byt 61,13,21,21,21,13,61,61

;;;<=>
_CG_DAT4
.byt 23,23,11,11,5,2,1,0	
.byt 63,63,63,63,63,30,33,30	
.byt 58,58,52,52,40,16,32,0
