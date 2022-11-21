struct stat {
    /* 4 */dev_t     st_dev;      /* ID du périphérique contenant le fichier */
    /* 8 */ino_t     st_ino;      /* Numéro inœud */
    /* 4 */mode_t    st_mode;     /* Protection */
    /* 4 */nlink_t   st_nlink;    /* Nb liens matériels */
    /* 4 */uid_t     st_uid;      /* UID propriétaire */
    /* 4 */gid_t     st_gid;      /* GID propriétaire */
    /* 4 */dev_t     st_rdev;     /* ID périphérique (si fichier spécial) */
    /* 8 */off_t     st_size;     /* Taille totale en octets */
    /* 8 */blksize_t st_blksize;  /* Taille de bloc pour E/S */
    /* 8 */blkcnt_t  st_blocks;   /* Nombre de blocs alloués */
    /* 8 */time_t    st_atime;    /* Heure dernier accès */
    /* 8 */time_t    st_mtime;    /* Heure dernière modification */
    /* 8 */time_t    st_ctime;    /* Heure dernier changement état */
