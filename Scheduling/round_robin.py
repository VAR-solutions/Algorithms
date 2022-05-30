import auxiliary as aux


class Schedule:
    def __init__(self, ready_queue, time_slice):
        self.rq = ready_queue.processes
        self.n = ready_queue.n
        self.ts = time_slice

    def ps_time(self):
        cpu_time = 0
        remaining = self.n
        flag = False
        i = 0

        r_times = [0] * self.n
        for i in range(self.n):
            r_times[i] = self.rq[i][2]

        while remaining:

            if self.ts >= r_times[i] > 0:
                cpu_time += r_times[i]
                r_times[i] = 0
                flag = True

            elif r_times[i] > 0:
                r_times[i] -= self.ts
                cpu_time += self.ts

            if r_times[i] == 0 and flag is True:
                remaining -= 1
                self.rq[i][4] = cpu_time - self.rq[i][1] - self.rq[i][2]
                self.rq[i][5] = cpu_time - self.rq[i][1]
                flag = False

            if i == self.n - 1:
                i = 0

            elif self.rq[(i + 1) % self.n][1] <= cpu_time:
                i += 1

            else:

                if r_times[i] == 0:
                    i += 1
                    cpu_time += self.rq[i % self.n][1] - cpu_time

                else:
                    i = 0

    def show(self):
        self.ps_time()
        print('\nROUND-ROBIN SCHEDULING : TIME-SLICE :- ' + str(self.ts))
        aux.show(self.rq, self.n)
