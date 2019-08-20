import pygame
import random
import math

#initialisation des graphismes et de l'écran
pygame.init()
window = pygame.display.set_mode((960,672))
screen = pygame.surface.Surface((240,224))
clock = pygame.time.Clock()

#lecture des sprites
board = pygame.image.load("board.png")
sprites = pygame.image.load("sprites.png")

#afficheur de sprite
def plot(source, pos, dest, area):
    dest.blit(source, (pos[0]*6,pos[1]), area)

#afficheur des nombres
def plotnumb(mode, pos, dest, numb, limit):
    text = str(numb)
    while len(text)<limit:
        text = "0"+text
    if mode == 1:
        for t,txt in enumerate(text):
            plot(sprites, (pos[0]+t*1,pos[1]), dest, ((ord(txt)-48)*6,16,6,8))
    if mode == 2:
        for t,txt in enumerate(text):
            plot(sprites, (pos[0]+t*2,pos[1]), dest, ((ord(txt)-47)*12,0,12,16))

#la cible, en tant qu'objet
class Ball:
    pos = [0,0]
    spd = [0,0]
    def move(self):
        self.pos[0] = self.pos[0] + self.spd[0]/30
        self.pos[1] = self.pos[1] - self.spd[1]/30
        self.spd[1] += -9.8/20
    def init(self):
        r = random.randint(0,1)
        if r:
            ang = math.radians(random.randint(-20,20)+135)
            self.pos = [234,152]
            self.spd = [math.cos(ang)*100,math.sin(ang)*random.randint(50,90)]
        else:
            ang = math.radians(random.randint(-20,20)+45)
            self.pos = [0,152]
            self.spd = [math.cos(ang)*100,math.sin(ang)*random.randint(50,90)]

#les positions pour l'afficheur de munitions
bullpos = [(x+1,8*x+16) for x in range(3,-1,-1)]+[(x+3,8*x+16) for x in range(4)]+[(x+5,8*x+16) for x in range(3,-1,-1)]+[(x+7,8*x+16) for x in range(4)]
bullpos.reverse()

#les variables du jeu
bullets = 16 #nb de munitions
score = 0
level = 1
targets = 16 #nb de cibles restantes
shot = 0     #si le joueur a tiré : 0 = Non ; 1 = Oui ; -1 = On attend que le bouton est laché

tim = 60 

#1re initialisation de la cible
ball = Ball()
ball.init()

#boucle du jeu
cont = True
while cont:
    screen.fill(0)                              #écran noir
    screen.blit(sprites, ball.pos, (0,0,6,8))   #affichage de la cible
    screen.blit(board, (0,0))                   #affichage du cadrant (le clavier)
    if ball.pos[1]<48:                              #si la cible va trop haut, on met un indicateur de position x
        screen.blit(sprites, [ball.pos[0],48], (6,0,6,8), pygame.BLEND_ADD)
    
    if shot==1:     #si le joueur a tiré
        sh = 1          #petite variable pour l'afficheur
        pygame.draw.rect(screen, 0xffffff, (60,40,180,8))       #gros rectangle qui représente la munition qui part
        shot = -1
    else: sh = 0
    for i in bullpos[sh:bullets+sh]:    #la variable sh sert à savoir combien de munition doit s'afficher
        plot(sprites, i, screen, (0,8,12,8))    #affichage des munitions
    plotnumb(2,(20,8), screen, score, 5)        #affichage du score
    plotnumb(1,(21,24), screen, level, 2)       #affichage du niveau
    
    #affichage du nb de cibles restantes sous forme de jauge
    pygame.draw.rect(screen, 0xffffff, (13,169,218,6), 1)   #cadran de la jauge
    ti = int((targets+tim/60-1)*212/16)    #variable de la jauge
    if ti!=0 and targets>0:
        pygame.draw.rect(screen, 0xffffff, (16,171,ti,2), 1)    #contenu de la jauge
    
    pygame.transform.scale(screen, (960,672), window)       #étirement de l'écran, pour que ça fasse Oric TV
    
    pygame.display.flip()       #affichage de l'image
    clock.tick(60)              #60 FPS
    
    if ball.pos[1]>160 or ball.pos[0]<-46 or ball.pos[0]>280:   #réinitialisation si la cible quitte l'écran sauf vers le haut
        if tim>0: tim -= 1     #on laisse une seconde avant la suivante
        else:
            if targets>0:
                targets -= 1    #y'a une cible en moins
                ball.init()
                tim = 60        #une seconde
    else:
        ball.move()         #mouvement de la cible
    
    key = pygame.key.get_pressed()      #ici, faudra programmer le clavier, les zones des touches, et si on touche la cible
    if key[pygame.K_SPACE]:
        if bullets>0:
            if shot == 0:
                shot = 1
                bullets -= 1
            
    else: shot = 0
    
    for event in pygame.event.get():        #pour quitter le programme
        if event.type == pygame.QUIT:
            cont = False
#pygame.quit()
