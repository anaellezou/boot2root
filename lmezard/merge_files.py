import os
import re

def main():
    dico = {}

    # loop on every files in current directory.
    for filename in os.listdir(os.getcwd()):
        with open(filename, 'r') as f:
            # store file content.
            file_content = f.read()

            # get file number
            try:
                file_number = re.search('.*//file(\d+)', file_content).group(1)
                file_number = int(file_number)
            except AttributeError:
                continue

            # remove fle number comment.
            file_content = re.sub('//file\d+', '', file_content)
            dico[file_number] = file_content

    # store saved content in order.
    with open('merged.c', 'a') as f:
        for i in range(1600):
            try:
                f.write(dico[i])
            except KeyError:
                continue


if __name__ == '__main__':
    main()
