#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    int id;
    int parentId;
    struct User *parent;
    struct User **children;
    int childrenCount;
    int childrenCapacity;
    int *movies;
    int movieCount;
    int movieCapacity;
} User;

#define INITIAL_CHILD_CAPACITY 4
#define INITIAL_MOVIE_CAPACITY 4

User *createUser(int id, User *parent);
void freeUser(User *user);
User *findUser(User *root, int id);
void addUser(User *root, int parentId, int userId);
void delUser(User *root, int userId);
void addMovie(User *root, int userId, int movieId);
void delMovie(User *root, int userId, int movieId);
void printUserMovies(User *root, int userId);

int main() {
    User *root = createUser(0, NULL);

    char command[50];
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "addUser") == 0) {
            int parentId, userId;
            scanf("%d %d", &parentId, &userId);
            addUser(root, parentId, userId);
        } else if (strcmp(command, "delUser") == 0) {
            int userId;
            scanf("%d", &userId);
            delUser(root, userId);
        } else if (strcmp(command, "addMovie") == 0) {
            int userId, movieId;
            scanf("%d %d", &userId, &movieId);
            addMovie(root, userId, movieId);
        } else if (strcmp(command, "delMovie") == 0) {
            int userId, movieId;
            scanf("%d %d", &userId, &movieId);
            delMovie(root, userId, movieId);
        } else if (strcmp(command, "printUserMovies") == 0) {
            int userId;
            scanf("%d", &userId);
            printUserMovies(root, userId);
        }
    }

    freeUser(root);
    return 0;
}

User *createUser(int id, User *parent) {
    User *user = (User *)malloc(sizeof(User));
    if (!user) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    user->id = id;
    user->parentId = parent ? parent->id : -1;
    user->parent = parent;
    user->children = (User **)malloc(sizeof(User *) * INITIAL_CHILD_CAPACITY);
    user->childrenCount = 0;
    user->childrenCapacity = INITIAL_CHILD_CAPACITY;
    user->movies = (int *)malloc(sizeof(int) * INITIAL_MOVIE_CAPACITY);
    user->movieCount = 0;
    user->movieCapacity = INITIAL_MOVIE_CAPACITY;
    return user;
}

void freeUser(User *user) {
    for (int i = 0; i < user->childrenCount; i++) {
        freeUser(user->children[i]);
    }
    free(user->children);
    free(user->movies);
    free(user);
}

User *findUser(User *root, int id) {
    if (root->id == id) {
        return root;
    }
    for (int i = 0; i < root->childrenCount; i++) {
        User *found = findUser(root->children[i], id);
        if (found) {
            return found;
        }
    }
    return NULL;
}

void addUser(User *root, int parentId, int userId) {
    User *parent = findUser(root, parentId);
    if (!parent || findUser(root, userId)) {
        printf("ERROR\n");
        return;
    }
    if (parent->childrenCount == parent->childrenCapacity) {
        parent->childrenCapacity *= 2;
        parent->children = (User **)realloc(parent->children, sizeof(User *) * parent->childrenCapacity);
    }
    User *newUser = createUser(userId, parent);
    parent->children[parent->childrenCount++] = newUser;
    printf("OK\n");
}

void delUser(User *root, int userId) {
    if (userId == 0) {
        printf("ERROR\n");
        return;
    }
    User *user = findUser(root, userId);
    if (!user) {
        printf("ERROR\n");
        return;
    }
    User *parent = user->parent;

    for (int i = 0; i < user->childrenCount; i++) {
        user->children[i]->parent = parent;
        if (parent->childrenCount == parent->childrenCapacity) {
            parent->childrenCapacity *= 2;
            parent->children = (User **)realloc(parent->children, sizeof(User *) * parent->childrenCapacity);
        }
        parent->children[parent->childrenCount++] = user->children[i];
    }

    for (int i = 0; i < parent->childrenCount; i++) {
        if (parent->children[i]->id == userId) {
            memmove(&parent->children[i], &parent->children[i + 1], (parent->childrenCount - i - 1) * sizeof(User *));
            parent->childrenCount--;
            break;
        }
    }

    free(user->movies);
    free(user->children);
    free(user);

    printf("OK\n");
}

void addMovie(User *root, int userId, int movieId) {
    User *user = findUser(root, userId);
    if (!user) {
        printf("ERROR\n");
        return;
    }
    for (int i = 0; i < user->movieCount; i++) {
        if (user->movies[i] == movieId) {
            printf("ERROR\n");
            return;
        }
    }
    if (user->movieCount == user->movieCapacity) {
        user->movieCapacity *= 2;
        user->movies = (int *)realloc(user->movies, sizeof(int) * user->movieCapacity);
    }
    user->movies[user->movieCount++] = movieId;
    printf("OK\n");
}

void delMovie(User *root, int userId, int movieId) {
    User *user = findUser(root, userId);
    if (!user) {
        printf("ERROR\n");
        return;
    }
    for (int i = 0; i < user->movieCount; i++) {
        if (user->movies[i] == movieId) {
            memmove(&user->movies[i], &user->movies[i + 1], (user->movieCount - i - 1) * sizeof(int));
            user->movieCount--;
            printf("OK\n");
            return;
        }
    }
    printf("ERROR\n");
}

void mergeSortedArrays(int *arr1, int size1, int *arr2, int size2, int *result, int *resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            result[k++] = arr2[j++];
        } else {
            result[k++] = arr1[i++];
            j++;
        }
    }
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    while (j < size2) {
        result[k++] = arr2[j++];
    }
    *resultSize = k;
}

void printUserMovies(User *root, int userId) {
    User *user = findUser(root, userId);
    if (!user) {
        printf("ERROR\n");
        return;
    }

    int parentMovies = user->parent ? user->parent->movieCount : 0;
    int totalMovies = user->movieCount + parentMovies;

    if (totalMovies == 0) {
        printf("\n");
        return;
    }

    int *mergedMovies = (int *)malloc(sizeof(int) * totalMovies);
    int mergedCount;

    if (user->parent) {
        mergeSortedArrays(user->movies, user->movieCount, user->parent->movies, parentMovies, mergedMovies, &mergedCount);
    } else {
        memcpy(mergedMovies, user->movies, sizeof(int) * user->movieCount);
        mergedCount = user->movieCount;
    }

    for (int i = 0; i < mergedCount; i++) {
        printf("%d ", mergedMovies[i]);
    }
    printf("\n");

    free(mergedMovies);
}
