# Asjade-internet-foor

# Kasutatud vahendid:
HTML, JS, CSS

Google firebase

Arduino App ja nodemcu esp 8266

Veebilehel on esitatud 2 foorid, ja nodemcuga 2 foorid, mõlemad on võimalik kontrollida veebilehel

# 4 nuppu:
Jalakäik - alustab pressForGreen funktsioon, mõlemad kui veebilehel kui nodemcu foorid alustavad jalakäija foori tsükli, ehk pea valgusfoor muutub punaseks ja jalakäia foor muutub roheliseks ja tsükkel tuleb tagasi

Vilkumine - alustab pressForYellow funktsioon, mõlemad pea foorid alustavad vilkuma kollase värviga

Roheline laine - kustutab pea algoritmi interval, ehk autoChange setinterval pidurtatakse

Auto režiim - alustab autoChange funktsioon tagasi, kui oli vajutatud Roheline laine nupp

# Arduino ja nodemcu
On kasutatud nodemcu ja arduino app, et panna käima lokaalne füsiline foor. On kasutatud nodemcu esp8266 plaat, 5 led lampi, 5 takistajad ja Arduino app, et settida koodi

# Firebase
Google kontos on võimalik kasutada firebase, mis annab võimalus kasutada databasi, kus on võimalik panna JSONi andmed ja kui on vaja muuta neid failid, sellega on tehtud nodemcu ja databasi ühendus, näiteks kui on vaja roheline led lampi põlema siis andmebaasi saadatalse objektina {"valgus1":"roheline"} jne.
