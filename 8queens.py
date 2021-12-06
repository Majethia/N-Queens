
ANSWERS = []

class Stack:
    def __init__(self):
        self.l = []

    def push(self, p):
        self.l.append(p);

    def remove(self):
        self.l.pop(-1)



def check_valid(q, t):
    if (q[0] == t[0]) or (t[1] == q[1]) or (q[0] - q[1] == t[0] - t[1]) or (q[0] + q[1] == t[0] + t[1]):
        return False
    return True


def place(s: Stack):
    if len(s.l) == 8:
        s.l.sort()
        if s.l not in ANSWERS:
            ANSWERS.append(s.l)
            print(f"Solution found: Solution number: {len(ANSWERS)}")
            print(s.l)
            return False


    for i in range(8):
        for j in range(8):
            t = (i, j)
            pushh = True
            for k in s.l:
                if not check_valid(k, t):
                    pushh = False
            if pushh:
                s.push(t)
                if not place(s):
                    s.remove()
                else:
                    return True
    return False


def main():
    s = Stack()
    place(s)


main()
