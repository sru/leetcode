class Solution:
    def interpret(self, command: str) -> str:
        i = 0
        interpretation = []
        while i < len(command):
            if command[i] == 'G':
                interpretation.append('G')
            elif command[i] == '(' and command[i+1] == ')':
                i += 1
                interpretation.append('o')
            else: # (al)
                i += 3
                interpretation.append('al')
            i += 1

        return ''.join(interpretation)
