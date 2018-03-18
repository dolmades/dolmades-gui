INSERT INTO descriptions (hash, display_name, description, author, distributor) VALUES (%docker_image_desc%, 'wine stable 3.0', 'Ubuntu 16.04 with wine 3.0, recent winetricks and its dependencies', 'Stefan Kombrink', 'dolmades.org');
INSERT INTO ingredients (hash, description, blob_type) VALUES (%docker_image_ingr%, %docker_image_desc%, 'IMAGE');
INSERT INTO urls (ingredient_hash, url) VALUES(%docker_image_ingr%, 'docker://katakombi/dolmades-winestable');

INSERT INTO descriptions (hash, display_name, description, author, distributor) VALUES (%gog_template_desc%, 'GOG template', 'DirectX9c gaming support', 'Stefan Kombrink', 'dolmades.org');
INSERT INTO recipes (hash, description, base_image) VALUES(%gog_template_recipe%, %gog_template_desc%, %docker_image_ingr%);

INSERT INTO descriptions (hash, display_name, description) VALUES (%broken_sword_desc%, 'Broken Sword 2.5', 'Adventure game, non-commercial, fan project');
INSERT INTO ingredients (hash, description, blob_type) VALUES(%broken_sword_ingr%, %broken_sword_desc%, 'EXECUTABLE');
INSERT INTO urls (ingredient_hash, url) VALUES(%broken_sword_ingr%, 'http://server.c-otto.de/baphometsfluch/bs25setup.zip');

INSERT INTO relates(recipe_hash, ingredient_hash, reltype) VALUES(%gog_template_recipe%, %broken_sword_ingr%, 'SUPPORTS');
