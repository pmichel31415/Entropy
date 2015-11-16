# Retrieves all text files from CNAM ABU (see license here : http://abu.cnam.fr/cgi-bin/donner_licence) for further treatment

import urllib.request

import os

from bs4 import BeautifulSoup, SoupStrainer

# Proxy handling
proxies = {'http':''}

opnr = urllib.request.build_opener(urllib.request.ProxyHandler(proxies))
urllib.request.install_opener( opnr )

with urllib.request.urlopen('http://abu.cnam.fr/BIB/') as response:
    html = response.read()
    # Search for all links towards a text file
    for link in BeautifulSoup(html, parseOnlyThese=SoupStrainer('a')):
        if link.has_attr('href'):
            if(link['href'].startswith('/cgi-bin/go')):
                name = link['href'].split('?')[1]
                print(name)
                # Download text file
                with urllib.request.urlopen('http://abu.cnam.fr/cgi-bin/donner_unformated?'+name) as response:
                    # Conversion to ISO-Latin 1
                    text = response.read().decode('ISO-8859-1', errors='replace')
                    lines = text.split('\n')
                    dir = 'Texts/'+name
                    os.mkdir(dir)
                    read=False
                    cnt=0
                    buffstring=''
                    # Reads text file from "DEBUT DU FICHIER" to "FIN DU FICHIER", regroups lines in packets of ~15000 chars and stores in text file
                    for i in range(len(lines)):
                        if "DEBUT DU FICHIER" in lines[i] or "FIN DU FICHIER" in lines[i]:
                            read = not(read)
                        l = len(buffstring)

                        if read:
                            if l>15000:
                                
                                f=open(dir+'/'+str(cnt)+'.txt','w',encoding='utf8')
                                f.write(buffstring)
                                f.close()
                                buffstring=''
                                cnt =cnt+1
                            else:
                                buffstring=buffstring+' '+lines[i]

                    if len(buffstring)>0:
                        f=open(dir+'/'+str(cnt)+'.txt','w',encoding='utf8')
                        f.write(buffstring)
                        f.close()
