<div>
    <div id="menu-header-logo" class="col-lg-2">
        <img src="img/logonoback.png" width="200px"/>
    </div>
    
    <div id="menu-header-top">
        <div class="col-lg-8 weather" >
			<?php
                require_once('inc/weather.php');
            ?>
        </div>
        <div id="conn" class="dd menu-item menu-item-type-post_type menu-item-object-page col-lg-2">Mon compte
        	<ul class="dd-content">
                <li><a  href="login.php">Se connecter</a></li>
				<li><a  href="register.php">Créer un compte</a></li>
			</ul>
        </div>
    </div>
</div>        

<nav id="menu-header-bottom" class="col-lg-12">
    <ul id="menu-primary-bottom" class="menu row">
        <li class="menu-item menu-item-type-post_type menu-item-object-page first col-lg-3">
            <a href="index.php">Accueil</a>
        </li>
        <li class="dd menu-item menu-item-type-post_type menu-item-object-page col-lg-3">
			<a href="services.php">Services</a>
        </li>
        <li class="menu-item menu-item-type-post_type menu-item-object-page col-lg-3">
            <a href="tarifs.php">Tarifs</a>
        </li>
        <li class="menu-item menu-item-type-post_type menu-item-object-page last col-lg-3">
            <a href="apropos.php">À propos</a>
        </li>
    </ul>
</nav>
