import turtle

with open('turtle', 'r') as f:

	raph = turtle.Turtle()

	for line in f:
		tab = line.split(" ")
		if tab[0] == "Tourne":
			if tab[1] == "gauche":
				raph.left(int(tab[3]))
			else:
				raph.right(int(tab[3]))
		elif tab[0] == "Avance":
			raph.forward(int(tab[1]))
		elif tab[0] == "Recule":
			raph.backward(int(tab[1]))