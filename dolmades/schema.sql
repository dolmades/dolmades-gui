PRAGMA foreign_keys = ON;

CREATE TABLE descriptions (
    hash           text PRIMARY KEY,
    display_name   text NOT NULL,
    description    text NOT NULL,
    author         text,
    distributor    text,
    logo           blob,
    logo_type      text,
    size_in_bytes  integer,
    CHECK(logo_type IN ("PNG","SVG","JPG"))
);

CREATE TABLE urls (
    ingredient_hash text,
    url             text NOT NULL,
    FOREIGN KEY (ingredient_hash) REFERENCES ingredients(hash)
);

CREATE TABLE ingredients (
    hash           text PRIMARY KEY,
    description    text,
    blob_type      text NOT NULL,
    CHECK(blob_type IN ("IMAGE", "REGISTRY", "EXECUTABLE", "RESOURCE")),
    FOREIGN KEY (description) REFERENCES descriptions(hash)
);

CREATE TABLE recipes (
    hash            text PRIMARY KEY,
    description     text NOT NULL,
    base_image      text NOT NULL,
    udocker_cmdline text,
    root_script     text,
    user_script     text,
    FOREIGN KEY (description) REFERENCES descriptions(hash),
    FOREIGN KEY (base_image) REFERENCES ingredients(hash)
);

CREATE TABLE dolmades (
    hash            text PRIMARY KEY,
    recipe          text NOT NULL,
    description     text NOT NULL,
    dir_path        text NOT NULL,
    FOREIGN KEY (recipe) REFERENCES recipes(hash),
    FOREIGN KEY (description) REFERENCES descriptions(hash)
);

CREATE TABLE relates (
    recipe_hash     text,
    ingredient_hash text,
    reltype         text,
    FOREIGN KEY (recipe_hash) REFERENCES recipes(hash),
    FOREIGN KEY (ingredient_hash) REFERENCES ingredients(hash),
    CHECK(reltype in ("REQUIRES", "SUPPORTS")),
    UNIQUE(recipe_hash, ingredient_hash, reltype)
);
