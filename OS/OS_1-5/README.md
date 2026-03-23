# AL3452 - Operating Systems Lab (All Experiments 1–15)

## Complete Experiment List

| Exp | Topic | File(s) | Compile Command |
|-----|-------|---------|-----------------|
| 1  | OS Installation | exp1/README.md | *(No code – manual task)* |
| 2  | Shell Programming | exp2/*.sh | `bash <filename>.sh` |
| 3  | Process Management (fork, exec, wait) | exp3/process_mgmt.c | `gcc process_mgmt.c -o process_mgmt` |
| 4a | FCFS Scheduling | exp4/fcfs.c | `gcc fcfs.c -o fcfs` |
| 4b | SJF Scheduling | exp4/sjf.c | `gcc sjf.c -o sjf` |
| 4c | Priority Scheduling | exp4/priority.c | `gcc priority.c -o priority` |
| 4d | Round Robin | exp4/round_robin.c | `gcc round_robin.c -o round_robin` |
| 5  | IPC – Shared Memory | exp5/shared_memory.c | `gcc shared_memory.c -o shared_memory` |
| 6  | Semaphore – Mutual Exclusion | exp6/semaphore.c | `gcc semaphore.c -o semaphore -lpthread` |
| 7  | Banker's Algorithm | exp7/bankers.c | `gcc bankers.c -o bankers` |
| 8  | Deadlock Detection | exp8/deadlock.c | `gcc deadlock.c -o deadlock` |
| 9  | Threading | exp9/threading.c | `gcc threading.c -o threading -lpthread` |
| 10 | Paging Technique | exp10/paging.c | `gcc paging.c -o paging` |
| 11 | Memory Allocation | exp11/memory_alloc.c | `gcc memory_alloc.c -o memory_alloc` |
| 12 | Page Replacement | exp12/page_replacement.c | `gcc page_replacement.c -o page_replacement` |
| 13 | File Organization | exp13/file_org.c | `gcc file_org.c -o file_org` |
| 14 | File Allocation | exp14/file_alloc.c | `gcc file_alloc.c -o file_alloc` |
| 15 | Disk Scheduling | exp15/disk_scheduling.c | `gcc disk_scheduling.c -o disk_scheduling` |

---

## Quick Run Reference

### Shell Scripts (Exp 2)
```bash
cd exp2
bash greatest.sh   # greatest of 2 numbers
bash sum_n.sh      # sum of n numbers
bash swap.sh       # swap 2 numbers
bash pos_neg.sh    # positive or negative
```

### C Programs (Exp 3–15)
```bash
# General pattern:
cd expN
gcc filename.c -o output_name      # compile
./output_name                      # run

# Exp 6 and 9 need -lpthread flag:
gcc semaphore.c -o semaphore -lpthread
gcc threading.c -o threading -lpthread
```

---

## Push to GitHub
```bash
cd os_lab
chmod +x push_to_github.sh
# Edit push_to_github.sh – add your GitHub username and repo name
./push_to_github.sh
```
