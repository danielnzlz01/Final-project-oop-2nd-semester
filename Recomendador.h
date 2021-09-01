using namespace std;

class Producto
{
  private:
    string titulo, duracion;
    int año;
    double rating;
				
	public:
    Producto(string titulo = "Sin título", double rating = 0.0, string duracion = "Sin duración", int año = 0)
		{
      this->titulo = titulo;
      this->rating = rating;
			this->duracion = duracion;
      this->año = año;
    }
    
    Producto(const Producto & producto)
		{
      this->titulo = producto.getTitulo();
      this->rating = producto.getRating();
      this->duracion = producto.getDuracion();
      this->año = producto.getAño();
		}

	  friend ostream& operator<<(ostream & salida, const Producto & producto);
    
    virtual string getTitulo() const
		{
      return this->titulo;
    }
    
    double getRating() const
		{
      return this->rating;
    }

    string getDuracion() const
		{
      return this->duracion;
    }
    
		int getAño() const
		{
			return this->año;
		}
    
    virtual string getSistema() const = 0;

  
    double operator > (const double rat) const{
      if (rating > rat){
        return 1;
      }
      else{
        return 0;
      }
    }

    double operator < (const double rat) const{
      if (rating < rat){
        return 1;
      }
      else{
        return 0;
      }
    }

    int operator >= (const int year) const{
      if (año >= year){
        return 1;
      }
      else{
        return 0;
      }
    }

    int operator <= (const int year) const{
      if (año <= year){
        return 1;
      }
      else{
        return 0;
      }
    }

    int operator == (const int year) const{
      if (año == year){
        return 1;
      }
      else{
        return 0;
      }
    }
};

ostream& operator<<(ostream & salida,  const Producto & producto)
{
    salida << producto.titulo << "," << producto.rating<< ","<< producto.duracion << "," << producto.año;
    return salida;
}

class ProductoNetflix : public Producto
{
  private:
    string director;
  public:
     ProductoNetflix(string titulo = "Sin título", double rating = 0.0, string duracion = "Sin duración", int año = 0, string director = "Sin director") : Producto(titulo, rating, duracion, año)
		{
      this->director = director;
    }

		string getSistema() const
    {
      return "Netflix";
    }

    string printSomething(){
      return this->director;
    }
  
};

class ProductoPrime : public Producto
{
  private:
    string idioma;
  public:
    ProductoPrime(string titulo = "Sin título", double rating = 0.0, string duracion = "Sin duración", int año = 0, string idioma = "Idioma desconocido") : Producto(titulo, rating, duracion, año)
		{
      this->idioma = idioma;
    }


    string getSistema() const
    {
      return "Prime Video";
    }

    string printSomething(){
      return this->idioma;
    }

};

class ProductoDisney : public Producto
{
  private:
    string reparto;
  public:
    ProductoDisney(string titulo = "Sin título", double rating = 0.0, string duracion = "Sin duración", int año = 0, string reparto = "Sin reparto") : Producto(titulo, rating, duracion, año)
		{
      this->reparto = reparto;
    }


    string getSistema() const
    {
      return "Diseny Plus";
    }

    string printSomething(){
      return this->reparto;
    }
};

class Netflix 
{
  private:
		vector<ProductoNetflix>productonetflix;
		void cargaDatos()
		{
			ifstream archivo("netflix_c.csv");
      string director, actors, country, enterNetflixDate, titulo, genero, calificacion,duration, id, fecha;

			string linea;

			getline(archivo, linea);

			while (getline(archivo, linea))
			{
				istringstream parser(linea);
        
        //cout << linea << endl;
				
				getline(parser, id, ',');
				getline(parser, titulo, ',');
				getline(parser, duration, ',');
        getline(parser, fecha, ',');
        getline(parser, genero, ',');
        getline(parser, director, ',');
        getline(parser, actors, ',');
        getline(parser, country, ',');
        getline(parser, calificacion, ',');
        getline(parser, enterNetflixDate, ',');

        int dAño = stoi(fecha.c_str(), NULL);
        double drating = strtod(calificacion.c_str(),NULL);
        ProductoNetflix ptempn = ProductoNetflix(titulo, drating, duration, dAño, director);
        productonetflix.push_back(ptempn);
			}
		}
    
  public:
		Netflix()
		{
			productonetflix = vector<ProductoNetflix>();
			cargaDatos();
		}
    
		vector<ProductoNetflix> getProductos(string consulta)
		{
			vector<ProductoNetflix> salida = vector<ProductoNetflix>();
     
			for(int i = 0; i < productonetflix.size(); i++)
			{
				if(productonetflix[i].getTitulo().find(consulta) != string::npos)
				{
          salida.push_back(productonetflix[i]);
        }
  		}
			return salida;
		} 

    vector<ProductoNetflix> getDuration(string consulta)
        {
          vector<ProductoNetflix> salida = vector<ProductoNetflix>();

          for(int i = 0; i < productonetflix.size(); i++)
          {
            if(productonetflix[i].getDuracion().find(consulta) != string::npos)
            {
              salida.push_back(productonetflix[i]);
            }
          }
          return salida;
        }

    vector<ProductoNetflix> getEntreAño(int año1, int año2){
    vector<ProductoNetflix> salida = vector<ProductoNetflix>();

      for(int i = 0; i < productonetflix.size(); i++){
        if(productonetflix[i] >= año1 && productonetflix[i] <= año2){
      		salida.push_back(productonetflix[i]);
        } 
      }
      return salida;
    }

    vector<ProductoNetflix> getAñoExacto(int añoExacto){
    vector<ProductoNetflix> salida = vector<ProductoNetflix>();

      for(int i = 0; i < productonetflix.size(); i++){
        if(productonetflix[i] == añoExacto){
      		salida.push_back(productonetflix[i]);
        } 
      }
      return salida;
    }

    vector<ProductoNetflix>  ratingMayor(double rating){
          vector<ProductoNetflix> salida = vector<ProductoNetflix>();

        for(int i = 0; i < productonetflix.size(); i++){
          if(productonetflix[i] > rating){
            salida.push_back(productonetflix[i]);
          } else{
            
          }
        }

        return salida;
      }
      

      vector<ProductoNetflix> ratingMenor(double rating){
          vector<ProductoNetflix> salida = vector<ProductoNetflix>();

        for(int i = 0; i < productonetflix.size(); i++){
          if(productonetflix[i] < rating){
            salida.push_back(productonetflix[i]);
          } else{
            
          }
        }

        return salida;
      }

		friend ostream& operator<<(ostream & salida, const Netflix & netflix);
		
  protected:
};

ostream& operator<<(ostream & salida, const Netflix & netflix)
{
  if(netflix.productonetflix.size() == 0)
	{
    salida<< "Empty";
  }
  for(int i = 0; i < netflix.productonetflix.size(); i++)
	{
    salida << netflix.productonetflix[i] << endl;
    salida << netflix.productonetflix[i].getSistema() << endl;
  }
  return salida;
}

class Prime
{
  private:
    vector<ProductoPrime>productoprime;
    void cargaDatos()
		{
			ifstream archivo("prime.csv");
			string titulo, idioma, imdbRating, duracion, añoLanzamiento, ratingEdad, descripcion;

			string linea;

			getline(archivo, linea);

			while (getline(archivo, linea))
			{

				istringstream parser(linea);
				
				getline(parser, titulo, '|');
				getline(parser, idioma, '|');
				getline(parser, imdbRating, '|');
				getline(parser, duracion, '|');
				getline(parser, añoLanzamiento, '|');
				getline(parser, ratingEdad, '|');
				getline(parser, descripcion, '|');

        int dAño = stoi(añoLanzamiento.c_str(), NULL);
        double drating = strtod(imdbRating.c_str(),NULL);
        ProductoPrime ptempp = ProductoPrime(titulo, drating, duracion, dAño, idioma);
        productoprime.push_back(ptempp);

			} 
		}
  public:
		Prime()
		{
			productoprime = vector<ProductoPrime>();
			cargaDatos();
    }

      vector<ProductoPrime> getProductos(string consulta){
      vector<ProductoPrime> salida = vector<ProductoPrime>();

        for(int i = 0; i < productoprime.size(); i++)
        {
          if(productoprime[i].getTitulo().find(consulta) != string::npos)
          {
            salida.push_back(productoprime[i]);
          }
        }
        return salida;
        }

      vector<ProductoPrime> getDuration(string consulta){
      vector<ProductoPrime> salida = vector<ProductoPrime>();

        for(int i = 0; i < productoprime.size(); i++)
        {
          if(productoprime[i].getDuracion().find(consulta) != string::npos)
          {
            salida.push_back(productoprime[i]);
          }
        }
        return salida;
        }

      vector<ProductoPrime> getEntreAño(int año1, int año2){
      vector<ProductoPrime> salida = vector<ProductoPrime>();

        for(int i = 0; i < productoprime.size(); i++)
				{
          if(productoprime[i] >= año1 && productoprime[i] <= año2)
					{
            salida.push_back(productoprime[i]);
          } 
        }
        return salida;
        }

      vector<ProductoPrime> getAñoExacto(int añoExacto){
      vector<ProductoPrime> salida = vector<ProductoPrime>();

        for(int i = 0; i < productoprime.size(); i++){
          if(productoprime[i] == añoExacto){
            salida.push_back(productoprime[i]);
          } 
        }
        return salida;
      }

      vector<ProductoPrime>  ratingMayor(double rating){
      vector<ProductoPrime> salida = vector<ProductoPrime>();

        for(int i = 0; i < productoprime.size(); i++){
          if(productoprime[i] > rating){
            salida.push_back(productoprime[i]);
          } 
        }
        return salida;
        }
        
      vector<ProductoPrime> ratingMenor(double rating){
      vector<ProductoPrime> salida = vector<ProductoPrime>();

        for(int i = 0; i < productoprime.size(); i++){
          if(productoprime[i] < rating){
            salida.push_back(productoprime[i]);
          }
        }
        return salida;
        }
        
		  friend ostream& operator<<(ostream & salida, const Prime & prime);
};

ostream& operator<<(ostream & salida, const Prime & prime)
{
  if(prime.productoprime.size() == 0)
	{
    salida<< "Empty";
  }
  for(int i = 0; i < prime.productoprime.size(); i++)
	{
    salida << prime.productoprime[i] << endl;
    salida << prime.productoprime[i].getSistema() << endl;
  }
  return salida;
}

class Disney
{
  private:
    vector<ProductoDisney>productodisney;
    void cargaDatos()
		{
			ifstream archivo("disney.csv");
			string id, titulo, descripcion, tipo, ratingEdad, añoLanzamiento, fechaAñadido, fechaAñadidoDos, duracion, genero, director, escritor, actores, idioma, pais, reconocimientos, metascoreRating, imdbRating, imdbVotos;

			string linea;

			getline(archivo, linea);

			//cout << linea;

			while (getline(archivo, linea))
			{
				// cout << linea << endl; //parsing
				istringstream parser(linea);
				
				getline(parser, id, '|');
				getline(parser, titulo, '|');
				getline(parser, descripcion, '|');
				getline(parser, tipo, '|');
				getline(parser, ratingEdad, '|');
				getline(parser, añoLanzamiento, '|');
				getline(parser, fechaAñadido, '|');
				getline(parser, fechaAñadidoDos, '|');
				getline(parser, duracion, '|');
				getline(parser, genero, '|');
				getline(parser, director, '|');
				getline(parser, escritor, '|');
				getline(parser, actores, '|');
				getline(parser, idioma, '|');
				getline(parser, pais, '|');
				getline(parser, reconocimientos, '|');
				getline(parser, metascoreRating, '|');
				getline(parser, imdbRating, '|');
				getline(parser, imdbVotos, '|');

        int dAño = stoi(añoLanzamiento.c_str(), NULL);
        double drating = strtod(imdbRating.c_str(),NULL);
        ProductoDisney ptempd = ProductoDisney(titulo, drating, duracion, dAño, actores);
        productodisney.push_back(ptempd);
				
			} 
		}
  public:
		Disney()
		{
			productodisney = vector<ProductoDisney>();
			cargaDatos();
		}

      vector<ProductoDisney> getProductos(string consulta){
      vector<ProductoDisney> salida = vector<ProductoDisney>();

        for(int i = 0; i < productodisney.size(); i++)
        {
          if(productodisney[i].getTitulo().find(consulta) != string::npos)
          {
            salida.push_back(productodisney[i]);
          }
        }
        return salida;
        }

      vector<ProductoDisney> getDuration(string consulta){
      vector<ProductoDisney> salida = vector<ProductoDisney>();

        for(int i = 0; i < productodisney.size(); i++)
        {
          if(productodisney[i].getDuracion().find(consulta) != string::npos)
          {
            salida.push_back(productodisney[i]);
          }
        }
        return salida;
        }

      vector<ProductoDisney> getEntreAño(int año1, int año2){
      vector<ProductoDisney> salida = vector<ProductoDisney>();

        for(int i = 0; i < productodisney.size(); i++){
          if(productodisney[i] >= año1 && productodisney[i] <= año2)
					{
            salida.push_back(productodisney[i]);
          } 
        }
        return salida;
        }

      vector<ProductoDisney> getAñoExacto(int añoExacto){
      vector<ProductoDisney> salida = vector<ProductoDisney>();

        for(int i = 0; i < productodisney.size(); i++){
          if(productodisney[i] == añoExacto){
            salida.push_back(productodisney[i]);
          } 
        }
        return salida;
      }

      vector<ProductoDisney>  ratingMayor(double rating){
      vector<ProductoDisney> salida = vector<ProductoDisney>();

        for(int i = 0; i < productodisney.size(); i++){
          if(productodisney[i] > rating){
            salida.push_back(productodisney[i]);
          } 
        }
        return salida;
        }
        
      vector<ProductoDisney> ratingMenor(double rating){
      vector<ProductoDisney> salida = vector<ProductoDisney>();

        for(int i = 0; i < productodisney.size(); i++){
          if(productodisney[i] < rating){
            salida.push_back(productodisney[i]);
          }
        }
        return salida;
        }

		friend ostream& operator<<(ostream & salida, const Disney & disney);
  protected:
};

ostream& operator<<(ostream & salida, const Disney & disney)
{
  if(disney.productodisney.size() == 0)
	{
    salida<< "Empty";
  }
  for(int i = 0; i < disney.productodisney.size(); i++)
	{
    salida << disney.productodisney[i] << endl;
    salida << disney.productodisney[i].getSistema() << endl;
  }
  return salida;
}

class Recomendador
{
  private:
    Netflix netflix;
    Disney disney;
    Prime prime;
    int opcion = -1;

 void menu(){

    cout << "\nIngrese la opcion que desee buscar: "<<endl;
    cout << "1 - Título: " << endl;
    cout << "2 - Rating mayor que: " << endl;
    cout << "3 - Rating menor que: " << endl;
    cout << "4 - Rango de años: " << endl;
    cout << "5 - Año exacto de película o serie: " << endl;
    cout << "6 - Duración: " << endl;
    cout << "0 - Salir" << endl;
    cout << "\nElige una opcion: ";

    bool menu = true;


    while(menu){

      string temp;
      getline(cin, temp);
      stringstream(temp) >> opcion;

      if(opcion == 1){

        string consulta = "";
        cout<< "\nIngresa el título de la película o serie: "<< endl;
        getline(cin,consulta);


        vector<ProductoNetflix> productonetflix = netflix.getProductos(consulta);
        for(int i = 0; i < productonetflix.size(); i++){
          cout << productonetflix[i] << endl;
          cout << "Y la encuentras en: " << productonetflix[i].getSistema() << endl;
        }

        vector<ProductoPrime> productoprime = prime.getProductos(consulta);
        for(int i = 0; i > productoprime.size(); i++){
          cout << productoprime[i] << endl;
          cout << "Y la encuentras en: " << productoprime[i].getSistema() << endl;
        }
        
        vector<ProductoDisney> productodisney = disney.getProductos(consulta);
        for(int i = 0; i < productodisney.size(); i++){
          cout << productodisney[i] << endl;
          cout << "Y la encuentras en: " << productodisney[i].getSistema() << endl;
        }

      }
      else if(opcion == 2){

        
        cout << "\nIngresa el rating mayor que: ";
				
        string temp2;
				double rating = 0;
				getline(cin, temp2);
				stringstream(temp2) >> rating;
      
  
        vector<ProductoNetflix> productonetflix = netflix.ratingMayor(rating);
        for(int i = 0; i < productonetflix.size(); i++){
        cout << productonetflix[i] << endl;
        cout << "Y la encuentras en: " << productonetflix[i].getSistema() << endl;
        } 

        vector<ProductoPrime> productoprime = prime.ratingMayor(rating);
        for(int i = 0; i > productoprime.size(); i++){
        cout << productoprime[i] << endl;
        cout << "Y la encuentras en: " << productoprime[i].getSistema() << endl;
        } 
        vector<ProductoDisney> productodisney = disney.ratingMayor(rating);
        for(int i = 0; i < productodisney.size(); i++){
        cout << productodisney[i] << endl;
        cout << "Y la encuentras en: " << productodisney[i].getSistema() << endl;
        } 

      }
      else if(opcion == 3){

        cout << "\nIngrese el rating menor que: ";
				
        string temp3;
				double rating = 0;
				getline(cin, temp3);
				stringstream(temp3) >> rating;

        vector<ProductoNetflix> productonetflix = netflix.ratingMenor(rating);
        for(int i = 0; i < productonetflix.size(); i++){
        cout << productonetflix[i] << endl;
        cout << "Y la encuentras en: " << productonetflix[i].getSistema() << endl;
        } 

        vector<ProductoPrime> productoprime = prime.ratingMenor(rating);
        for(int i = 0; i > productoprime.size(); i++){
        cout << productoprime[i] << endl;
        cout << "Y la encuentras en: " << productoprime[i].getSistema() << endl;
        } 

        vector<ProductoDisney> productodisney = disney.ratingMenor(rating);
        for(int i = 0; i < productodisney.size(); i++){
        cout << productodisney[i] << endl;
        cout << "Y la encuentras en: " << productodisney[i].getSistema() << endl;
        } 

      }
      else if(opcion == 4){
        
        cout << "\nIngresa rango de años de menor a mayor: "<< endl;
        cout << "Año 1: " ;

				string temp4;
				int año1 = 0;
				getline(cin, temp4);
				stringstream(temp4) >> año1;
        
				
        cout << "Año 2: ";

        string temp5;
				int año2 = 0;
				getline(cin, temp5);
				stringstream(temp5) >> año2;

        vector<ProductoNetflix> productonetflix = netflix.getEntreAño(año1, año2);
        for(int i = 0; i < productonetflix.size(); i++){
          cout << productonetflix[i] << endl;
          cout << "Y la encuentras en: " << productonetflix[i].getSistema() << endl;
        } 

        vector<ProductoPrime> productoprime = prime.getEntreAño(año1, año2);
        for(int i = 0; i < productoprime.size(); i++){
          cout << productoprime[i] << endl;
          cout << "Y la encuentras en: " << productoprime[i].getSistema() << endl;
        } 

        vector<ProductoDisney> productodisney = disney.getEntreAño(año1, año2);
        for(int i = 0; i < productodisney.size(); i++){
          cout << productodisney[i] << endl;
          cout << "Y la encuentras en: " << productodisney[i].getSistema() << endl;
        } 

      }
      else if(opcion == 5){
        
        cout << "\nIngresa año de película o serie: " << endl;

        string temp6;
				int año = 0;
				getline(cin, temp6);
				stringstream(temp6) >> año;

        vector<ProductoNetflix> productonetflix = netflix.getAñoExacto(año);
        for(int i = 0; i < productonetflix.size(); i++){
          cout << productonetflix[i] << endl;
          cout << "Y la encuentras en: " << productonetflix[i].getSistema() << endl;
        }

        vector<ProductoPrime> productoprime = prime.getAñoExacto(año);
        for(int i = 0; i > productoprime.size(); i++){
          cout << productoprime[i] << endl;
          cout << "Y la encuentras en: " << productoprime[i].getSistema() << endl;
        }
        
        vector<ProductoDisney> productodisney = disney.getAñoExacto(año);
        for(int i = 0; i < productodisney.size(); i++){
          cout << productodisney[i] << endl;
          cout << "Y la encuentras en: " << productodisney[i].getSistema() << endl;
        }
      }
      else if(opcion == 6){
        
        cout << "\nIngresa duración de película o serie: " << endl;

				string temp7;
				string consulta = "";
				getline(cin, temp7);
				stringstream(temp7) >> consulta;

        vector<ProductoNetflix> productonetflix = netflix.getDuration(consulta);
        for(int i = 0; i < productonetflix.size(); i++){
          cout << productonetflix[i] << endl;
          cout << "Y la encuentras en: " << productonetflix[i].getSistema() << endl;
        }

        vector<ProductoPrime> productoprime = prime.getDuration(consulta);
        for(int i = 0; i > productoprime.size(); i++){
          cout << productoprime[i] << endl;
          cout << "Y la encuentras en: " << productoprime[i].getSistema() << endl;
        }
        
        vector<ProductoDisney> productodisney = disney.getDuration(consulta);
        for(int i = 0; i < productodisney.size(); i++){
          cout << productodisney[i] << endl;
          cout << "Y la encuentras en: " << productodisney[i].getSistema() << endl;
        }
      }
      
        
      

      try{
      if (opcion < 0)
      {
        throw "Debe elegir la opción 1, 2, 3, 4, 5 ó 6";

      }
      else if (opcion > 6)
      {
        throw 0;
      }
      }catch(const char * opcion_incorrecta)
      {
      cout << opcion_incorrecta << endl;
        menu = false;
      }catch(int mayor_seis)
      {
      cout << "OPCIÓN INCORRECTA!!" << endl;
        menu = false;
      } 
    menu = false;
    }
  }

  public:
  
    Recomendador(){
      while (true)
      {
        menu();
        if (this->opcion == 0)
       {
       	break;
       }
      }
      
    }
};