import configparser
import os

from executing import Source

src = './src/'

f = open('./config.json','r')

def Source_Scan(src):
    for entry in os.scandir(src):
        if entry.is_file():


Config = configparser.ConfigParser()
Config.read('./user.conf')

def main():
    Source_Scan(src)