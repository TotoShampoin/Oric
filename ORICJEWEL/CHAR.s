_CG_DEFCHAR
.(
	lda #<_CG_DATA
	sta tmp0
	lda #>_CG_DATA
	sta tmp0+1
	lda #$D8
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
	
;;;;;

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

;;;;

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
;;;;

	lda #<_CG_DAT5
	sta tmp0
	lda #>_CG_DAT5
	sta tmp0+1
	lda #$F0
	sta tmp1
	lda #$B7
	sta tmp1+1
		
	ldy #8
boucle5
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle5
;;;;;
	lda #<_CG_DAT6
	sta tmp0
	lda #>_CG_DAT6
	sta tmp0+1
	lda #$08
	sta tmp1
	lda #$BA
	sta tmp1+1
		
	ldy #0
boucle6
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle6

;;;;;
	lda #<_CG_DAT7
	sta tmp0
	lda #>_CG_DAT7
	sta tmp0+1
	lda #$08
	sta tmp1
	lda #$BB
	sta tmp1+1
		
	ldy #72
boucle7
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle7

;;;;; lettres
	lda #<_CG_DAT8
	sta tmp0
	lda #>_CG_DAT8
	sta tmp0+1
	lda #$08
	sta tmp1
	lda #$B6
	sta tmp1+1
		
	ldy #208
boucle8
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle8
	
;;;;; chiffres
	lda #<_CG_DAT9
	sta tmp0
	lda #>_CG_DAT9
	sta tmp0+1
	lda #$80
	sta tmp1
	lda #$B5
	sta tmp1+1
		
	ldy #80
boucle9
	dey
	lda (tmp0),y
	sta (tmp1),y
	cpy #0
	bne boucle9
	rts
.)

_CG_DATA
;;; rien
;;;.byt 0,0,0,0,0,0,0,0
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
.byt 0,1,3,7,7,15,15,31
.byt 0,32,48,56,56,60,60,62
.byt 31,31,31,15,15,7,1,0
.byt 62,62,62,60,60,56,32,0
;;; 4
.byt 0,3,7,15,31,31,31,31
.byt 0,48,56,60,62,62,62,62
.byt 31,31,31,31,15,7,3,0
.byt 62,62,62,62,60,56,48,0
;;; 5
.byt 0,15,31,31,31,31,15,15
.byt 0,60,62,62,62,62,60,60
.byt 15,7,7,3,3,1,1,0
.byt 60,56,56,48,48,32,32,0
;;; 6
.byt 0,1,1,3,3,3,7,7
.byt 0,32,32,48,48,48,56,56
.byt 7,15,15,15,31,31,31,0
.byt 56,60,60,60,62,62,62,0
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

_CG_DAT5
.byt 30,63,63,30,30,12,12,0

_CG_DAT6
.byt 0,1,7,15,15,31,30,30
.byt 0,32,56,60,60,62,30,30
.byt 0,62,62,62,62,0,0,0
.byt 0,31,31,31,31,0,0,0
.byt 0,31,31,31,31,30,30,30
.byt 0,62,62,62,62,30,30,30
.byt 0,3,7,15,31,16,30,30
.byt 0,63,63,63,63,0,63,63
.byt 0,48,56,60,62,2,30,30
.byt 30,30,30,30,30,62,60,60
.byt 30,30,31,15,15,7,1,0
.byt 30,30,62,60,60,56,32,0
.byt 0,0,0,62,62,62,62,0
.byt 0,0,0,31,31,31,31,0
.byt 30,30,30,31,31,31,31,0
.byt 30,30,30,62,62,62,62,0
.byt 30,31,15,15,15,7,7,7
.byt 63,30,30,30,30,30,30,30
.byt 30,62,60,60,60,56,56,56
.byt 60,60,62,30,30,30,30,30
.byt 30,30,30,30,30,30,31,31
.byt 30,30,30,30,30,30,62,62
.byt 30,30,30,30,30,30,30,0
.byt 0,30,30,30,30,30,30,30
.byt 0,63,63,63,63,30,30,30
.byt 30,30,30,63,63,63,63,0
.byt 3,3,3,1,1,1,0,0
.byt 45,45,45,45,45,45,45,51
.byt 48,48,48,32,32,32,0,0
.byt 0,0,0,0,0,0,62,62
.byt 31,31,30,30,30,30,30,30
.byt 62,62,30,30,30,30,30,30

_CG_DAT7
.byt 0,63,63,63,63,0,0,0
.byt 30,30,30,30,30,30,30,30
.byt 0,0,0,63,63,63,63,0
.byt 0,0,0,0,0,0,63,63
.byt 63,63,0,0,0,0,0,0
.byt 51,18,18,18,12,12,12,0
.byt 0,0,0,0,0,0,0,0
.byt 62,62,0,0,0,0,0,0

;;;; lettres A-Z
_CG_DAT8
.byt 0,28,34,62,34,34,0,0
.byt 0,60,34,60,34,60,0,0
.byt 0,30,32,32,32,30,0,0
.byt 0,60,34,34,34,60,0,0
.byt 0,62,32,60,32,62,0,0
.byt 0,62,32,60,32,32,0,0
.byt 0,30,32,46,34,30,0,0
.byt 0,34,34,62,34,34,0,0
.byt 0,28,8,8,8,28,0,0
.byt 0,2,2,2,34,28,0,0
.byt 0,34,34,60,34,34,0,0
.byt 0,32,32,32,32,62,0,0
.byt 0,34,54,42,34,34,0,0
.byt 0,34,50,42,38,34,0,0
.byt 0,28,34,34,34,28,0,0
.byt 0,60,34,60,32,32,0,0
.byt 0,28,34,34,38,30,0,0
.byt 0,60,34,60,34,34,0,0
.byt 0,30,32,28,2,60,0,0
.byt 0,62,8,8,8,8,0,0
.byt 0,34,34,34,34,28,0,0
.byt 0,34,34,34,20,8,0,0
.byt 0,34,34,42,54,34,0,0
.byt 0,34,20,8,20,34,0,0
.byt 0,34,34,20,8,8,0,0
.byt 0,62,4,8,16,62,0,0

;;;;; chiffres
_CG_DAT9
.byt 28,62,54,54,54,62,28,0
.byt 12,28,28,12,12,30,30,0
.byt 28,62,38,12,24,62,62,0
.byt 62,62,12,30,6,62,28,0
.byt 6,14,30,54,62,62,6,0
.byt 62,62,32,62,6,62,28,0
.byt 28,62,48,60,54,62,28,0
.byt 62,62,6,14,28,24,24,0
.byt 28,62,54,28,54,62,28,0
.byt 28,62,54,30,6,62,28,0