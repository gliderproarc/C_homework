import os.path


if __name__ == '__main__':
    filename = "FoxDog.txt"
    if not os.path.isfile(filename):
        # testing if the files exists
        print('File does not exist')
    else:
        with open(filename) as f:
            content = f.read()
            word_list = content.split(' ')
            # text is now split by spaces and ready to be written in reverse
            e = open("python_rev_text.txt",'w')
            e.close()
            # blanking the file if it exists first
            ex = open("python_rev_text.txt",'a')
            for word in word_list:
                ex.write(word[::-1])
                ex.write(' ')
            ex.close()
            f.close()
