import pygame
from classes import bullet
#from classes import laser
#from classes import enemy

class Hero(pygame.sprite.Sprite):

    def __init__(self, x, y):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load('assets/Player.png').convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y
        self.move = 25
        self.ships = 3
        self.bullet = bullet.Bullet()

    #def update(self,screen):
        #screen.blit(self.image, (self.x, self.y))

    def movement(self, input):
        speed = 10
        if input == "UP" and self.rect.y >=0:
            self.rect.y -= self.move
        elif input == "DOWN" and self.rect.y <= 650:
            self.rect.y += self.move


    #Might need to adjust the movement values

    def fire(self, screen):
        self.bullet.shoot(screen, 100, self.rect.y)
        print("bullet fired")

        #Work on when bullet class is working

    #def death(self):
