def main(nb):
    if nb <= 1:
        return (1)
    return (main(nb-1) + main(nb-2))

for i in range(20):
    res = main(i)
    print(f"main({i}) = {res}")
