# Isotherme Messdaten
set terminal png
set output 'kritische_daten_isotherm.png'

set xlabel "V [mm^3]"
set ylabel "P [bar]"

set xrange [0:15000]
set yrange [0:40]

set title "Kritische Daten Isotherme"
set grid

set style data linespoints

plot "messdaten/isotherm_25.dat" using 1:2 title "T = 25 °C", \
     "messdaten/isotherm_35.dat" using 1:2 title "T = 35 °C", \
     "messdaten/isotherm_45.dat" using 1:2 title "T = 45 °C", \
     "messdaten/isotherm_50.dat" using 1:2 title "T = 50 °C"

# Isochore Messdaten
set terminal png
set output 'kritische_daten_isochor.png'

set xlabel "T [°C]"
set ylabel "P [bar]"

set xrange [20:55]
set yrange [0:40]

set title "Kritische Daten Isochore"
set grid

set style data linespoints

plot "messdaten/isochor_20.dat" using 1:2 title "V = 6280 mm^3 (20mm)", \
     "messdaten/isochor_30.dat" using 1:2 title "V = 9420 mm^3 (30mm)", \
     "messdaten/isochor_40.dat" using 1:2 title "V = 12560 mm^3 (40mm)"