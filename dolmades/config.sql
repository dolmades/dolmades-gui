INSERT INTO descriptions (hash, display_name, description, author, distributor) VALUES ('CDEF', 'wine stable 3.0', 'Ubuntu 16.04 with wine 3.0, recent winetricks and its dependencies', 'Stefan Kombrink', 'dolmades.org');
INSERT INTO ingredients (hash, description, blob_type ) VALUES ('ABCD','CDEF','IMAGE');
INSERT INTO urls (ingredient_hash, url) VALUES('ABCD','docker://katakombi/dolmades-winestable');

INSERT INTO descriptions (hash, display_name, description, author, distributor) VALUES ('GHIJ', 'GOG template', 'DirectX9 gaming support', 'Stefan Kombrink', 'dolmades.org');
INSERT INTO recipes (hash, description, base_image) VALUES('OPQR', 'GHIJ', 'ABCD');

INSERT INTO descriptions (hash, display_name, description) VALUES ('UVW', 'Broken Sword 2.5', 'Adventure game, non-commercial, fan project');
INSERT INTO urls (ingredient_hash, url) VALUES('JK', 'http://server.c-otto.de/baphometsfluch/bs25setup.zip');

INSERT INTO relates(recipe_hash, ingredient_hash, reltype) VALUES('OPQR', 'JK', 'SUPPORTS');
